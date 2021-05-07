#include<bits/stdc++.h>
using namespace std;

void printNumsLexico(int x, int n) {

    if(x > n) return;
    if(x == n) {
        cout << x << endl;
        return;
    }

    if(x != 0) cout << x << endl;

    for(int i = (x == 0) ? 1 : 0; i <= 9; i++) {
        printNumsLexico(x * 10 + i, n);
    }
}

int main(){
    int n = 13, x  = 0;

    printNumsLexico(x, n);

    return 0;
}