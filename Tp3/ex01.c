#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>


#define N 1000000


// we will start by initializing an array of N random integers between 0 and 100.
// Then, we will create parallel sections to compute the sum and the maximum value of the array.
// Finally, we will compute the mean and standard deviation of the array elements.


int main() {
    int *array = malloc(N * sizeof(int));
    long long sum = 0;
    int max = 0;

    for (int i = 0; i < N; i++) {
        array[i] = rand() % 100;
    }

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            long long local_sum = 0;
            for (int i = 0; i < N; i++) {
                local_sum += array[i];
            }
            #pragma omp atomic /// this means add local_sum to shared total sum, but make sure that only one thread can modify sum at a time  
            sum += local_sum;
        }

        #pragma omp section
        {
            int local_max = array[0];
            #pragma omp parallel for reduction(max:local_max) /// each thread computes its own local max, and at the end the maximum of all local maxes is computed
            for (int i = 1; i < N; i++) {
                if (array[i] > local_max) {
                    local_max = array[i];
                }
            }
            #pragma omp critical /// this means that one threads at time can modify the max value
            {
                if (local_max > max) {
                    max = local_max;
                }
            }
        }
    }

    // let's calculate the standard deviation as well
    double mean = (double)sum / N;
    double variance = 0.0;
    #pragma omp parallel for reduction(+:variance)
    for (int i = 0; i < N; i++) {
        variance += (array[i] - mean) * (array[i] - mean);
    }

    double stddev = sqrt(variance / N);

    #pragma omp parallel
    {
        #pragma omp single
        {
            printf("Sum = %lld\n", sum);
            printf("Max = %d\n", max);
            printf("Mean = %f\n", mean);
            printf("Stddev = %f\n", stddev);
        }
    }

    free(array);
    return 0;
}













