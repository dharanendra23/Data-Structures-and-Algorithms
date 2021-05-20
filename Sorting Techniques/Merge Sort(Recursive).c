#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void generateRandArray(int arr[]) {

	for(int i = 0; i < SIZE; ++i) {

		arr[i] = rand();
	}
}

void merge(int arr[], int l, int m, int h) {

	int ind1 = m-l+1, ind2 = h-m;
	int arr1[ind1], arr2[ind2];

	for(int i = 0; i < ind1; i++) {

		arr1[i] = arr[l+i];
	}

	for (int i = 0; i < ind2; ++i) {
		
		arr2[i] = arr[m+1+i];
	}

	int left = 0, right = 0, i = l;

	while(left < ind1 && right < ind2) {

		if(arr1[left] <= arr2[right]) arr[i++] = arr1[left++];
		else arr[i++] = arr2[right++];
	}

	while(left < ind1) arr[i++] = arr1[left++];

	while(right < ind2) arr[i++] = arr2[right++]; 
}
 
void mergeSort(int arr[], int l, int h) {

	if(l < h) {

		int mid = (l + h) / 2;
		mergeSort(arr, l, mid);
		mergeSort(arr, mid+1, h);

		merge(arr, l, mid, h);
	}
}

int main() {

	int arr[SIZE];

	generateRandArray(arr);

	int n = SIZE;

	// arr[] before sorting
	for(int i = 0; i < SIZE; ++i) {

		printf("%d ", arr[i]);
	}
	printf("\n");

	mergeSort(arr, 0, n-1);

	// arr[] after sorting
	for(int i = 0; i < SIZE; ++i) {

		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}