#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h> // Include the OpenMP header

double f(double x) {
    return x / (1 + fabs(x) + x * x);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <N> <num_threads>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    int num_threads = atoi(argv[2]);
    double a = -4.0;
    double b = 4.0;
    double dx = (b - a) / (N - 1);
    double sum = 0.5 * (f(a) + f(b));

    omp_set_num_threads(num_threads); // Set the number of threads for OpenMP

    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i < N - 1; i++) {
        double xi = a + i * dx;
        sum += f(xi);
    }

    double result = dx * sum;
    printf("%.20f\n", result);

    return 0;
}

