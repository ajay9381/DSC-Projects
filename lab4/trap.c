#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <N>\n", argv[0]);
        return 1; // Return an error code if no argument is provided.
    }

    int N = atoi(argv[1]); // Convert input to an integer using atoi.

    printf("i=%d\n", N);

    if (N < 2) {
        printf("N should be greater than or equal to 2.\n");
        return 1; // Return an error code if N is less than 2.
    }

    double dx = 2.0 / (N - 1); // Calculate dx as a double.

    for (int i = 0; i < N; i++) {
        double x = -1.0 + dx * i;
        printf("x=%e\n", x); // Use a comma, not a semicolon.
    }

    return 0; // Return 0 to indicate successful execution.
}

