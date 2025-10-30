#include <stdio.h>
#include <mpi.h>
int main(int argc, char** argv) {
   
    // let's start by the MPI  program that prints just "Hello World"
    MPI_Init(&argc, &argv); // Initialize the MPI environment
    //printf("Hello World\n");
    int world_size; // number of processes
    // Get the number of processes
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    printf("Number of processes: %d\n", world_size);

    int world_rank; // rank of the process
    // Get the rank of the process
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    printf("Hello World from process %d out of %d processes\n", world_rank, world_size);

    MPI_Finalize(); // Finalize the MPI environment
    