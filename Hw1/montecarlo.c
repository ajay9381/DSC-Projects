#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Define the function f(x) = 1 / (1 + x^2)
double function(double x) {
    return 1.0 / (1.0 + x * x);
}

int main() {
    int num_trials = 10;
    int max_N = 1 << 20; // 2^20 (you can adjust this value)
    double total_error;
    const int V = 2;

    // Seed the random number generator with the current time
    srand((unsigned int)time(NULL));

    // Create a file to store the results
    FILE *fp = fopen("montecarlo_data.csv", "w");
    if (fp == NULL) {
        perror("Error opening the file");
        return 1;
    }

    fprintf(fp, "N, AverageAbsoluteError\n");

    for (int i = 1; i <= 20; i++) { // Reduced from 30
        int N = 1 << i; // N = 2^i
        double total_sum = 0.0;

        for (int trial = 0; trial < num_trials; trial++) {
            total_error = 0.0;

            // Generate random values and calculate the sum
            for (int j = 0; j < N; j++) {
                double xi = -1.0 + 2.0 * (double)rand() / RAND_MAX; // Random number between -1 and 1
                total_sum += function(xi);
            }

            // Calculate the approximate integral
            double approx_integral = (V / (double)N) * total_sum;
            total_error += fabs(M_PI / 2.0 - approx_integral);
        }

        // Calculate the average absolute error
        double avg_error = total_error / num_trials;

        fprintf(fp, "%d, %lf\n", N, avg_error);

        // Check the elapsed time
        clock_t elapsed_time = clock();
        double elapsed_seconds = (double)elapsed_time / CLOCKS_PER_SEC;
        if (elapsed_seconds > 60.0) { // 60 seconds = 1 minute
            break;
        }
    }

    // Close the file
    fclose(fp);


    // Execute the Bash script
    int status = system("./runTrials.sh");

    if (status == 0) {
    printf("Bash script executed successfully.\n");
    } else {
    printf("Error executing the Bash script.\n");
    }

    return 0;
}
