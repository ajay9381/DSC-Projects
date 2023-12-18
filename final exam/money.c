#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    double principal = 1000;  // The principal amount
    double rate = 0.05;       // Annual interest rate
    double amount;            // Final amount
    int years;

    // Check if an argument is provided
    if (argc != 2) {
        printf("Usage: %s <years>\n", argv[0]);
        return 1;
    }

    // Convert the argument to an integer
    years = atoi(argv[1]);

    // Calculate the final amount
    amount = principal * pow(1 + rate, years);

    // Output the result
    printf("%.2f\n", amount);

    return 0;
}

