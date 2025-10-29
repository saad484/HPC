/******************************************
 * 
 * Allocate an array of doubles, initializes it to 1.0
 * Preforms a summation while traversing the array with
 * differents strides.
 *
 *******************************************/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define MAX_STRIDE 20

int main(){

int N = 1000000;
double *a;

a = malloc(N * MAX_STRIDE * sizeof(double));
double sum, rate, msec, start, end;

for (int i = 0; i < N * MAX_STRIDE; i++)
	a[i] = 1.;

printf("stride__,__sum,__time__(msec),__rate__(MB/s)\n");
for (int i_stride = 1; i_stride <= MAX_STRIDE;i_stride)
{
	sum = 0.0;
	start = (double)clock() / CLOCKS_PER_SEC;

	for (int i = 0; i < N * i_stride; i += i_stride)
		sum += a[i];

	end = (double) clock() / CLOCKS_PER_SEC;
	msec = (end - start) * 1000.0; //time in milliseconds
	rate = sizeof(double) * N * (1000.0 / msec) / (1024 * 1024);

	printf("%d,__%f,__%f,__%f\n", i_stride, sum, msec, rate);

}
free(a);
}
