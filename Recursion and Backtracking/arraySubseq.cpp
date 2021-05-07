#include<bits/stdc++.h>
using namespace std;

// Recursion
// void arrSubSeq(int arr[], int n, int i, string osf) {

//     if(i == n) {
//         cout <<"[" << osf << "]" <<endl;
//         return;
//     }

//     arrSubSeq(arr, n, i+1, osf);
  
//     arrSubSeq(arr, n-1, i+1, osf + to_string(arr[n-1]) + " ");
// }

// Backtracking
void arrSubSeq(int *arr, vector<int>& vect, int i, int n) {
    if(i == n) {
        if(vect.size() > 0) {
            for(int j = 0; j < vect.size(); j++) {
                cout << vect[j] << " ";
            }
            cout << endl;
        }
        return;
    }

    vect.push_back(arr[i]);
    arrSubSeq(arr, vect, i+1, n);
    vect.pop_back();
    arrSubSeq(arr, vect, i+1, n);
}

int main() {

    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vect; 

    arrSubSeq(arr, vect, 0, n);    

    return 0;
}