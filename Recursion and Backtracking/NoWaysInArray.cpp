#include<bits/stdc++.h>
using namespace std;

int ans = 0;

void noOfWays(int n, int i, string osf) {

    if(i == n-1) {
        cout << osf << endl;
        ans++;
        return;
    }

    if(i > n) return;

    for(int j = 1; j <= 6; j++) {
        noOfWays(n, i+j, osf + to_string(j) + " ");
    }
}

int main() {

    int n = 3;

    noOfWays(n, 0, "");
    
    cout << "Total no : " << ans << endl;

    return 0;
}