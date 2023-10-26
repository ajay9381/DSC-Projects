#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double snowfall_pdf(double S) {
    if (S >= 0 && S <= 10) {
        double denominator = 2.4496028273129427;
        double exponent = -0.5 * fabs(S - 2) * fabs(S - 2);
        return 1.0 / denominator * exp(exponent);
    } else {
        return 0.0;
    }
}

double monte_carlo_snowfall(int N, int num_trials) {
    double V = 10.0; // The range of integration [0, 10]
    double total_snowfall = 0.0;

    for (int trial = 0; trial < num_trials; trial++) {
        double trial_sum = 0.0;

        for (int i = 0; i < N; i++) {
            double random_S = 10.0 * (double)rand() / RAND_MAX; // Random number between 0 and 10
            double pdf_value = snowfall_pdf(random_S);
            trial_sum += random_S * pdf_value;
        }

        double approx_integral = (V / N) * trial_sum;
        total_snowfall += approx_integral;
    }

    double average_snowfall = total_snowfall / num_trials;
    return average_snowfall;
}

int main() {
    int num_trials = 1000;
    srand(42); // Seed the random number generator with a constant value for reproducibility
    double result = monte_carlo_snowfall(1000, num_trials);

    printf("The expected average value of snowfall in January is approximately %lf meters.\n", result);

    return 0;
}


