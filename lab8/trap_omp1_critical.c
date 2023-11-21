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
    double integral = 0.0;

    // add contribution at x=-1
    double x = -1.0;
    double f = 1.0 / (1.0 + x * x);
    integral = integral + 0.5 * dx * f;

    // add contribution at x=1
    x = 1.0;
    f = 1.0 / (1.0 + x * x);
    integral = integral + 0.5 * dx * f;

    #pragma omp parallel for private(x, f) reduction(+:integral)
    for (int i = 1; i < N - 1; ++i) {
        x = -1.0 + dx * i; // compute x_i
        f = 1.0 / (1.0 + x * x); // compute f_i = f(x_i)
        #pragma omp critical
        integral = integral + dx * f;
        // printf("thread %i, i=%d, x=%f, f=%f\n", omp_get_thread_num(), i, x, f); // for diagnostics
    }

    const double pi = 3.141592653589793;
    double absolute_error = fabs(integral - pi / 2.0);
    printf("%i %1.2e\n", N, absolute_error);

    return 0;
}

