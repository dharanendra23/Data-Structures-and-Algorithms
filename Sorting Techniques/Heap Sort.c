#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void generateRandArray(int arr[]) {

	for(int i = 1; i <= SIZE; i++) {

		arr[i] = rand();
	}
}

void swap(int *a, int *b) {

	int temp = *a;
	*a = *b;
	*b = temp;
}

void insert(int arr[], int n) {

	int i = n/2;
	int j = n;
	while(i >= 1) {

		if(arr[j] > arr[i]) swap(&arr[i], &arr[j]);
		else break;
		j = i;
		i /= 2;		
	}
}

void createHeap(int arr[], int n) {

	for(int i = 2; i <= n; ++i) {

		insert(arr, i);
	}
}

void delete(int arr[], int n) {

	int temp = arr[1];
	arr[1] = arr[n];
	int i = 1;
	int j = 2*i;

	while(i < n && j < n) {

		if(arr[j+1] > arr[j]) j++;

		if(arr[j] > arr[i]) swap(&arr[i], &arr[j]);
		else break;
		i = j;
		j *= 2;
	}

	arr[n] = temp;
}

void heapSort(int arr[], int n) {

	createHeap(arr, n);

	for(int i = n; i >= 1; i--) {

		delete(arr, i);
	}
}

int main() {

	int arr[SIZE+1];

	generateRandArray(arr);

	// arr[] before sorting
	for(int i = 1; i <= SIZE; ++i) {

		printf("%d ", arr[i]);
	}
	printf("\n");

	int n = SIZE;
	heapSort(arr, n);

	// arr[] after sorting
	for(int i = 1; i <= SIZE; ++i) {

		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
