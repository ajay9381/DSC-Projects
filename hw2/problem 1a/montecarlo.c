#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
FILE *outputFile; // File pointer for output
    outputFile = fopen("pi_results.dat", "w");
    int k,N;
    double pi_approx =0.0;
    double x1,x2;
    for (k = 2;k <= 8;k++) {
         N = pow(10, k);
        int inside_circle = 0;

        srand(time(NULL));

        for (int i = 0; i < N; i++) {
             x1 = (double)rand() / RAND_MAX * 2 - 1; 
             x2 = (double)rand() / RAND_MAX * 2 - 1; 

            if (x1 * x1 + x2 * x2 <= 1.0) {
                inside_circle++;
            }
        }
        pi_approx = 4.0 * inside_circle / N;
        printf("For k = %d ,N = %d, pi_approx ≈ %f\n", k, N, pi_approx);
        fprintf(outputFile,"%d, %.10f\n",N, pi_approx);
    }

    return 0;
}
