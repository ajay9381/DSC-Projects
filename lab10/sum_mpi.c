#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int rank, size, local_sum = 0, global_sum = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Calculate local sum
    for (int i = rank + 1; i <= 100; i += size) {
        local_sum += i;
    }

    // Perform MPI reduction to get global sum
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Print the result from the root process
    if (rank == 0) {
        printf("The sum of numbers from 1 to 100 is: %d\n", global_sum);
    }

    MPI_Finalize();

    return 0;
}

