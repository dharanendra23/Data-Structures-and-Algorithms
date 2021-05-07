#include<bits/stdc++.h>
using namespace std;

void pattern(int n, int i) {

    if(n == 0) return;

    if(i < n) {
        cout << "* ";
        pattern(n, i+1);
    } else{
        cout << endl;
        pattern(n-1, 0);
    }
}

void pattern2(int n, int i) {

    if(n == 0) return;

    if(n > i) {
        pattern2(n-1, i);
    }
    // else {
        cout << "*";
        pattern2(n, i+1);
    //}
    cout << endl;
}

int main() {

    int n = 4;

    //pattern(n, 0);
    pattern2(n, 0);
    return 0;
}