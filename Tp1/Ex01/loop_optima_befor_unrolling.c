#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 100000000

int main(){
	double *arr = malloc(N * sizeof(double));
	clock_t  start, end;
	double time, sum = 0.0;

	if (!arr){
		printf("Memory allocation failed\n");
		return 1;
	}
	

	// Initializing the array
	for (int i = 0; i < N; i++){
		arr[i] = 1.0;
	}	

	start = clock();

	for (int i = 0; i < N; i++){

		sum +=arr[i];

	}
	end = clock();

	time = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("SUM NORMAL :%.2f | Time: %.4f sec\n", sum, time);


	free(arr);
	return 0;
}
