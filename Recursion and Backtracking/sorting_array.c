#include<stdio.h>

void sort(int arr[], int n){
    if(n == 0){
        return;
    }

    sort(arr, n-1);

    if(arr[n] < arr[n-1]){
        int temp = arr[n];
        arr[n] = arr[n-1];
        arr[n-1] = temp;
    }

    sort(arr, n-1);
}

int main(){
    int arr[] = {5, 3, 4, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    sort(arr, n);
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}