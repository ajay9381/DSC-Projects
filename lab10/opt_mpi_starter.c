#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <mpi.h> // include MPI library header

void sample_rand(const double a, const double b, const int dim, double *x);
double f(double *x);

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv); // initializes MPI
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // get current MPI-process ID. 0, 1, ...
    MPI_Comm_size(MPI_COMM_WORLD, &size); // get the total number of processes
    long N = atol(argv[1]);
    srand(time(NULL) * rank); // each MPI process gets a unique seed
    const int dim = 2; // dimension of function to optimize (x1, x2)
    double x[dim]; // array of random numbers
    // search for the function's maximum
    double max = -1;
    for (long int i = 1; i <= N; ++i) {
        sample_rand(-1.0, 1.0, dim, x);
        double f_i = f(x);
        // printf("Process %d: sample number %ld of %ld, f_i = %e \n", rank, i, N, f_i);
        if (f_i > max) {
            max = f_i;
        }
    }
    printf("Process %d of %d local max = %e \n", rank, size, max);
    // CODE FOR YOU TO WRITE HERE AS PART OF THIS LAB 10!
    double global_max = -100;
    // Use MPI_Reduce to find the global maximum and store it in the variable
    // global_max on processor 0.
    MPI_Reduce(&max, &global_max, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        printf("Global max = %e \n", global_max);
    }
    MPI_Finalize(); // programs should always perform a "graceful" shutdown
    return 0;
}

// will sample any dim-dimensional box of size [a, b]^dim
// the random point is stored in the array x
void sample_rand(const double a, const double b, const int dim, double *x) {
    for (int i = 0; i < dim; ++i) {
        double tmp = ((double)rand()) / ((double)RAND_MAX);
        x[i] = (b - a) * tmp + a;
    }
}

// pass array x, and unpack its elements inside the function
// NOTE: this is a way to pass an array of arbitrary size into a function
double f(double *x) {
    double x1 = x[0];
    double x2 = x[1];
    return exp(-(1. - x1) * (1. - x1) - 100. * (x2 - x1 * x1) * (x2 - x1 * x1));
}

