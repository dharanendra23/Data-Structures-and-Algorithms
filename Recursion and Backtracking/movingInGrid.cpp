#include<bits/stdc++.h>
using namespace std;

// My approach
int moveInGrid(int d, int r, int n, int m, string osf) {
    static int cnt;

    if(d == n && r == m) {
        cout << osf << endl;
        cnt++;   
        return cnt;
    }

    if(d > n || r > m) return cnt;
    
    moveInGrid(d, r+1, n, m, osf+"R"); 
    
    moveInGrid(d+1, r, n, m, osf+"D");

    return cnt;        
}

// Sanket sir approach
int cntMoves(int d, int r, int n, int m, string osf){

    if(d == n && r == m){
        cout << osf << endl;
        return 1;
    }

    if(d > n || r > m) {
        return 0;
    }

    int cnt1 = cntMoves(d, r+1, n, m, osf + "R");
    int cnt2 = cntMoves(d+1, r, n, m, osf + "D");

    return cnt1 + cnt2;
}

int main() {
    int n = 3, m = 3;

    //cout << moveInGrid(0, 0, n-1, m-1, "") << endl;

    cout << cntMoves(0, 0, n-1, m-1, "") << endl;

    return 0;
}