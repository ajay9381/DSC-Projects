#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char **argv) {
    srand(time(NULL)); // Initialize the random number generator
    int N = atoi(argv[1]); 
    FILE *file = fopen("rand_numbers.dat", "w");
    for (int i = 0; i < N; ++i) {
        int rand_int = rand();
        // Converting the integer to a double in the range [0, 1]
        double x = (double)rand_int / RAND_MAX;
        // Printing the random number
        printf("%f\n",x);
        fprintf(file, "%lf\n",x);
    }
      // Closing the file
    fclose(file);
    return 0;
}
