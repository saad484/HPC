// #include <stdio.h>


// static long num_steps = 100000;
// double step;
// int i; double x, pi, sum = 0.0;

// int main(){
//     step = 1.0/(double) num_steps;
    
//     for (i = 0; i < num_steps; i++){
//         x = (i + 0.5) * step;
//         sum += 4.0 / (1.0 + x*x);
//     }

//     pi = step * sum;
//     printf("Pi is approximately: %.16f\n", pi);

// }


 // create a prallel version of the above code using parallel constructs from OpenMP
 // Don't use #pragma omp parallel for
 // Pay close attention to data shared versus private variables
 // Use double opt_get_wtime() to measure to calculate the cpu time.


// -> 

#include <stdio.h>
#include <omp.h>

static long num_steps = 100000;
double step;
int i; double x, pi, sum = 0.0;
double start_time, end_time;

int main(){
    step = 1.0/(double) num_steps;
    start_time = omp_get_wtime();

    #pragma omp parallel
    {
        double x;
        double local_sum = 0.0;
        #pragma omp for
        for (i = 0; i < num_steps; i++){
            x = (i + 0.5) * step;
            local_sum += 4.0 / (1.0 + x*x);
        }
        #pragma omp atomic
        sum += local_sum;
    }

    pi = step * sum;
    end_time = omp_get_wtime();
    printf("Pi is approximately: %.16f\n", pi);
    printf("Time taken: %.6f seconds\n", end_time - start_time);
}




/** Mr. MP * version of pi calculation **/

#include <stdio.h>
#include <omp.h>

int main()
{
    static long num_steps = 1000000;
    double step;
    double x, pi, sum = 0.0;
    double start, end;

    step = 1.0 / (double)num_steps;

    start = omp_get_wtime();

    #pragma omp parallel for private(x) reduction(+:sum)
    for (int i = 0; i < num_steps; i++)
    {
        x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }

    pi = step * sum;
    end = omp_get_wtime();

    printf("Value of pi = %.15f\n", pi);
    printf("Execution time = %f seconds\n", end - start);

    return 0;
