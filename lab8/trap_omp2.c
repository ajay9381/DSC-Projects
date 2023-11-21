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

    omp_set_num_threads(4); // set the number of threads to 4
    double dx = 2.0 / (N - 1); // delta x spacing when the interval is [-1, 1]
    double x, f; // declare x and f here
    double integral_thread[4] = {0}; // initialize each thread's contribution to zero
    double integral = 0.0;

    #pragma omp parallel private(x, f)
    {
        int id = omp_get_thread_num();

        #pragma omp for
        for (int i = 1; i < N - 1; ++i) {
            x = -1.0 + dx * i; // compute x_i
            f = 1.0 / (1.0 + x * x); // compute f_i = f(x_i)
            integral_thread[id] = integral_thread[id] + dx * f;
        }
    }

    // accumulate each thread's contribution to the total integral
    for (int i = 0; i < 4; i++) {
        integral = integral + integral_thread[i];
    }

    const double pi = 3.141592653589793;
    double absolute_error = fabs(integral - pi / 2.0);
    printf("%i %1.2e\n", N, absolute_error);

    return 0;
}

