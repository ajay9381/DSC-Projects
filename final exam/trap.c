#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double f(double x) {
    return x / (1 + fabs(x) + x * x);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <N>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    double a = -4.0;
    double b = 4.0;
    double dx = (b - a) / (N - 1);

    double sum = 0.5 * (f(a) + f(b));

    for (int i = 1; i < N - 1; i++) {
        double xi = a + i * dx;
        sum += f(xi);
    }

    double result = dx * sum;

    printf("%.20f\n", result);

    return 0;
}

