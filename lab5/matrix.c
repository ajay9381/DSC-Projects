#include<stdio.h>
// This function shows how to pass an array or matrix to a function
// Call this function from within the main program.
void residual(double b[2], double x[2], double A[2][2]) {
    // Print components of the residual r = b - Ax
    // matrix-vector dot product... "input" is A and x, and "output" is Ax = A*x
    double AX[2] = {0}; // initialize to zero
    for (int i = 0; i < 2; i++) {
        // now compute i-th component of AX
        for (int j = 0; j < 2; j++) {
            AX[i] += A[i][j] * x[j];
        }
    }
    // print the residual
    for (int i = 0; i < 2; i++) {
        printf("residual[%i] = %1.10e\n", i, b[i] - AX[i]);
    }
}
int main() {
    // declare vectors here
    double x[2], x1[2], x2[2], b[2];
    double A[2][2];

    x[0] = 1.0;
    x[1] = -1.0;

    // Set values for x1, x2, and b
    x1[0] = 0.9999999;
    x1[1] = -1.0000001;

    x2[0] = 0.4073666;
    x2[1] = -0.1945277;

    b[0] = 0.1869169;
    b[1] = 0.2155734;

    A[0][0] = 0.7073725;
    A[0][1] = 0.5204556;
    A[1][0] = 0.8158208;
    A[1][1] = 0.6002474;
   // Calculate A Â· x
    double Ax[2] = {0};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            Ax[i] += A[i][j] * x[j];
        }
    }
    for (int i = 0; i < 2; i++) {
        printf("%f\n", Ax[i]);
    }
    // Calculate residuals for x, x1, and x2
    printf("Residual for x:\n");
    residual(b, x, A);

    printf("Residual for x1:\n");
    residual(b, x1, A);

    printf("Residual for x2:\n");
    residual(b, x2, A);

    return 0;
}
