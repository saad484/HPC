/*****
* Exersice 1: (Hello World)
*
* 1 - Write an MPI program that prints the message "Hello World".
* 2 - Each process should print its rank and the total number of processes.
* 3 - Modify the program so that only the process with rank 0 print a message. This is useful when you run with hundreds of processes.
* 4  - what happens if you omit the final MPI procedure call MPI_Finalize() ?
*****/

#include <stdio.h>
#include <mpi.h>
int main(int argc, char** argv) {
   
    // let's start by the MPI  program that prints just "Hello World"
    MPI_Init(&argc, &argv); // Initialize the MPI environment
    printf("Hello World\n");
    MPI_Finalize(); // Finalize the MPI environment

  
    /* Only let the process with rank 0 perform printing. This avoids
       hundreds of duplicate messages when running with many processes. */

       // what do we mean by rank 0 process?
       // In an MPI program, each process is assigned a unique rank (ID) within the communicator.
       // The rank is used to distinguish between different processes and to control the flow of the program.
       // The process with rank 0 is often referred to as the "master" process.
       // In many cases, the master process is responsible for coordinating the work of the other processes.
       // It may distribute tasks to worker processes and collect results from them.

    // if (world_rank == 0) {
    //     printf("Number of processes: %d\n", world_size);
    //     printf("Hello World from process %d out of %d processes\n", world_rank, world_size);
    // } 
  
    // MPI_Finalize(); // Finalize the MPI environment
    
    
    return 0;
}