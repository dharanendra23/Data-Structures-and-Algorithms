#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void generateRandArray(int arr[]) {

	for(int i = 0; i < SIZE; ++i) {
		
		arr[i] = rand();
	}
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp; 
}

void bubbleSort(int arr[], int n) {

	// n-1 steps
	for(int i = 0; i < n-1; ++i) {

		// flag to check is array sorted in any step
		// so to stop it their itself
		int flag = 0;

		for(int j = 0; j < n-1-i; ++j) {

			if(arr[j] > arr[j+1]) {

				swap(&arr[j], &arr[j+1]);
				flag = 1;
			}
		}
		if(flag == 0) break;
	}
}

int main() {

	int arr[SIZE];

	generateRandArray(arr);

	// arr[] before sorting
	for(int i = 0; i < SIZE; ++i) {

		printf("%d ", arr[i]);
	}
	printf("\n");

	int n = SIZE;
	bubbleSort(arr, n);

	// arr[] after sorting
	for(int i = 0; i < SIZE; ++i) {

		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}