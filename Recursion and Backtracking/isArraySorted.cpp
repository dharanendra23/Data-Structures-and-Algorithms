#include<bits/stdc++.h>
using namespace std;

void isArraySorted(int arr[], int n) {
    if(n == 0) {
        cout << "Array is sorted" << endl;
        return;
    }

    if(arr[n] < arr[n-1]) {
        cout << "Array is not sorted" << endl;
        return;
    }

    isArraySorted(arr, n-1);
}

int main() {
    int arr[] = {1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    isArraySorted(arr, n-1);

    return 0;
}