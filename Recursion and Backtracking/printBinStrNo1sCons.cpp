#include<bits/stdc++.h>
using namespace std;


void binStr(int n, int i, string osf) {

    if(n == 0) {
        cout << osf << endl;
        return;
    }

    binStr(n-1, i+1,osf + "0");

    if(osf[i-1] != '1')
        binStr(n-1, i+1,osf + "1");
}

int main() {

    int n = 4;

    binStr(n, 0, "");

    return 0;
}