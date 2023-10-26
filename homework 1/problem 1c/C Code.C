#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the function f(x) = 1 / (1 + x^2)
double function(double x) {
    return 1.0 / (1.0 + x * x);
}

int main() {
    int N;
    double total_sum = 0.0;
    const int V = 2;

    // Seed the random number generator with the current time
    srand((unsigned int)time(NULL));

    // Prompt the user for the number of random samples (N)
    printf("Enter the number of random samples (N): ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("N must be a positive integer.\n");
        return 1;
    }

    // Generate random values and calculate the sum
    for (int i = 0; i < N; i++) {
        double xi = -1.0 + 2.0 * (double)rand() / RAND_MAX; // Random number between -1 and 1
        total_sum += function(xi);
    }

    // Calculate the approximate integral
    double approx_integral = (V / (double)N) * total_sum;

    printf("Approximate Integral (ˆI1(N)): %lf\n", approx_integral);

    return 0;
}
