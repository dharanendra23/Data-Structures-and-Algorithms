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
 
int partition(int arr[], int l, int h) {

	int pivot = arr[l];
	int i = l, j = h;

	do{

		do{i++;}while(arr[i] <= pivot);
		do{j--;}while(arr[j] > pivot);

		if(i < j) swap(&arr[i], &arr[j]);

	}while(i < j);

	swap(&arr[l], &arr[j]);

	return j;
}

void quickSort(int arr[], int l, int h) {

	if(l < h) {

		int pos = partition(arr, l , h);

		quickSort(arr, l, pos);
		quickSort(arr, pos+1, h);
	}
}

int main() {

	int arr[SIZE+1];
	arr[SIZE] = INT_MAX;
	generateRandArray(arr);

	int n = SIZE + 1;

	// arr[] before sorting
	for(int i = 0; i < SIZE; ++i) {

		printf("%d ", arr[i]);
	}
	printf("\n");

	quickSort(arr, 0, n-1);

	// arr[] after sorting
	for(int i = 0; i < SIZE; ++i) {

		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
