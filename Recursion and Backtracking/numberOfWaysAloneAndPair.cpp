#include<bits/stdc++.h>
using namespace std;

int numberOfWays(int n) {

    if(n == 1 || n == 2) return n;

    int cand1 = numberOfWays(n - 1);
    int cand2 = (n-1) * numberOfWays(n - 2);

    return cand1 + cand2;
}

int main() {

    int n = 4;

    cout << numberOfWays(n) << endl;

    return 0;
}