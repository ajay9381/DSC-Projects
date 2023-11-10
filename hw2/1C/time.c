#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double monteCarloPi(int N)
{
    int insideCircle = 0;
    srand(time(NULL)); // Initialize random seed
    
    for (int i = 0; i < N; i++) 
    {
        double x = (double)rand() / RAND_MAX * 2 - 1; // Random x coordinate in [-1, 1]
        double y = (double)rand() / RAND_MAX * 2 - 1; // Random y coordinate in [-1, 1]
        
        if (x*x + y*y <= 1) 
        {
            insideCircle++;
        }
    }
    
    return 4.0 * insideCircle / N;
}

int main() 
{
    clock_t start = clock();
    int k;
    
    for (k = 2; k <= 8; k++) 
    {
       
        long int N = 1;
        for (int i = 0; i < k; i++) 
        {
            N *= 10;
        }
        const double pi = 3.141592653589793;
        double piApproximation = monteCarloPi(N);
        double absolute_error = fabs(pi-piApproximation);
        //printf("For N = %ld, Approximated Pi = %f\n", N, piApproximation);
        //printf("%ld %f\n", N, absolute_error);
        //printf("%f\n",absolute_error);
        clock_t end = clock();
        double execution_time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%ld %f %f\n",N,absolute_error,execution_time);
        
    }
    
    return 0;
}

