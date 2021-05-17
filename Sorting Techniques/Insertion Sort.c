#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void generateRandArray(int arr[]) {

	for(int i = 0; i < SIZE; ++i) {

		arr[i] = rand();
	}
}

void insertionSort(int arr[], int n) {

	for(int i = 1; i < n; ++i) {

		int temp = arr[i];
		int j = i - 1;
		while(j >= 0 && arr[j] > temp) {

			arr[j+1] = arr[j];
			j--;
		} 
		arr[j+1] = temp;
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
	insertionSort(arr, n);

	// arr[] after sorting
	for(int i = 0; i < SIZE; ++i) {

		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}