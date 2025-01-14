#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <mpi.h>

void sample_rand(const double a, const double b, const int dim, double *x);
double f(double *x);

int main(int argc, char **argv) {
    int rank,size;
    MPI_Init(&argc,&argv);//initializes MPI
    MPI_Comm_rank(MPI_COMM_WORLD,&rank); //get current MPIâˆ’process ID . O, 1 , . . .
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    long N = atol(argv[1]);

    // Set seed for random number generation
    srand(time(NULL) * rank);

    const int dim = 2; // dimension of function to optimize (x1,x2)
    double x[dim]; // array of random numbers
    double max = -1;

    for (long int i=1;i<=N;++i){
        sample_rand(-1.0, 1.0, dim, x);
        double f_i = f(x);
        printf("Process %d: sample number %ld of %ld, f_i = %1.5e\n", rank, i, N, f_i);
        if (f_i > max) {
            max = f_i;
        }
    }
    printf("Process %d of %d local max = %1.5e\n", rank, size, max);

    MPI_Finalize();
    return 0;
}

void sample_rand(const double a, const double b, const int dim, double *x) {
    for (int i = 0; i < dim; ++i) {
        double tmp = ((double)rand()) / ((double)RAND_MAX);
        x[i] = (b-a)* tmp + a;
    }
}
double f(double *x) {
    double x1 = x[0];
    double x2 = x[1];
    return exp(-(1.0 - x1)*(1.0 - x1) - 100.0 * (x2 - x1 * x1)*(x2 - x1 * x1));
}

