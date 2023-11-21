#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <N>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]); // convert command-line input to N = number of points
    if (N <= 1) {
        fprintf(stderr, "N should be greater than 1.\n");
        return 1;
    }

    double dx = 2.0 / (N - 1); // delta x spacing when the interval is [-1, 1]
    double integral = 0.0;

    // Serial code
    double start_time_serial = omp_get_wtime();

    // add contribution at x=-1
    double x = -1.0;
    double f = 1.0 / (1.0 + x * x);
    integral = integral + 0.5 * dx * f;

    // add contribution at x=1
    x = 1.0;
    f = 1.0 / (1.0 + x * x);
    integral = integral + 0.5 * dx * f;

    // compute the integral over the remaining interval
    for (int i = 1; i < N - 1; ++i) {
        x = -1.0 + dx * i; // compute x_i
        f = 1.0 / (1.0 + x * x); // compute f_i = f(x_i)
        integral = integral + dx * f;
    }

    double end_time_serial = omp_get_wtime();
    printf("Serial: %i %1.9f seconds\n", N, end_time_serial - start_time_serial);

    double start_time, end_time; // variables to store the start and end time
    omp_set_num_threads(4); // set the number of threads to 4

    // OpenMP parallelization 1 (trap_omp1_critical.c)
    start_time = omp_get_wtime();
    #pragma omp parallel for reduction(+:integral) private(x, f)
    for (int i = 1; i < N - 1; ++i) {
        x = -1.0 + dx * i;
        f = 1.0 / (1.0 + x * x);
        integral = integral + dx * f;
    }
    end_time = omp_get_wtime();
    printf("OpenMP (critical): %1.9f seconds\n", end_time - start_time);

    // OpenMP parallelization 2 (trap_omp1_atomic.c)
    integral = 0.0; // Reset integral for the next parallelization
    start_time = omp_get_wtime();
    #pragma omp parallel for private(x, f) shared(integral)
    for (int i = 1; i < N - 1; ++i) {
        x = -1.0 + dx * i;
        f = 1.0 / (1.0 + x * x);
        #pragma omp atomic
        integral = integral + dx * f;
    }
    end_time = omp_get_wtime();
    printf("OpenMP (atomic): %1.9f seconds\n", end_time - start_time);

    // OpenMP parallelization 3 (trap_omp2.c)
    integral = 0.0; // Reset integral for the next parallelization
    double integral_thread[4] = {0.0}; // Array to store partial integrals from each thread
    start_time = omp_get_wtime();
    #pragma omp parallel private(x, f)
    {
        int id = omp_get_thread_num();
        #pragma omp for
        for (int i = 1; i < N - 1; ++i) {
            x = -1.0 + dx * i;
            f = 1.0 / (1.0 + x * x);
            integral_thread[id] = integral_thread[id] + dx * f;
        }
    }
    // Sum the partial integrals from each thread
    for (int i = 0; i < 4; ++i) {
        integral = integral + integral_thread[i];
    }
    end_time = omp_get_wtime();
    printf("OpenMP (reduction): %1.9f seconds\n", end_time - start_time);

    return 0;
}

