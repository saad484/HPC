#include <stdio.h>
#include <stdlib.h>


/****
- Write an OpenMP program that displays the number of threads used for the execution. and the rank of each thread.
- Complile the code manully to create monoprocess exacutable and a parallel executable.
- Test the program with different number of threads for the parallel program, without submitting in batch.
*/


int main(int argc, char *argv[]) {

    // possible output :
    // Hello from the rank 2 thread
    // Parallel execution of hello_world with 4 threads

    #ifdef NUM_THREADS
        // Monoprocess execution
        printf("Hello from the rank 0 thread\n");
        printf("Monoprocess execution of hello_world with 1 thread\n");
    #else
        // Parallel execution
        #pragma omp parallel
        {
            int rank = omp_get_thread_num();
            printf("Hello from the rank %d thread\n", rank);
        }
        int num_threads = omp_get_max_threads();
        printf("Parallel execution of hello_world with %d threads\n", num_threads);
    #endif

    return 0;
}

// To compile the code for a monoprocess executable, use:
// gcc -o ex01_mono ex01.c -fopenmp -DNUM_THREADS
// To compile the code for a parallel executable, use:
// gcc -o ex01_parallel ex01.c -fopenmp
// To run the parallel executable with a specific number of threads, use:
// export OMP_NUM_THREADS=4
// ./ex01_parallel
