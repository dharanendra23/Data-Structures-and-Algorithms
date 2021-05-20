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

void mergeIterativeSort(int arr[], int n) {

	int i;
	for(i = 2; i <= n; i *= 2) {

		for(int j = 0; j+i-1 < n; j += i) {

			int l = j;
			int h = j+i-1;
			int mid = (l + h)/2;
			merge(arr, l, mid, h);
		}
	}

	if(i/2 < n)
		merge(arr, 0, i/2-1, n-1);
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
	mergeIterativeSort(arr, n);

	// arr[] after sorting
	for(int i = 0; i < SIZE; ++i) {

		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}