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

void selectionSort(int arr[], int n) {

	for(int i = 0; i < n; i++) {

		int k, j;
		for(k=j=i; j < n; j++) {

			if(arr[j] < arr[k]) k = j;
		}
		swap(&arr[i], &arr[k]);
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
	selectionSort(arr, n);

	// arr[] after sorting
	for(int i = 0; i < SIZE; ++i) {

		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}