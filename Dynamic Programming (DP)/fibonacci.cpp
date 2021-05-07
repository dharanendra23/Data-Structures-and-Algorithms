#include<bits/stdc++.h>
using namespace std;

// Memoization(Recursion logic + storage) or Top-down approach
int fibonacci(int n, vector<int> &dp) {

    if(n == 0 or n == 1) return n;

    if(dp[n] != -1) return dp[n]; // if already stored then return the value present at n
    int ans = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
    dp[n] = ans; // storing

    return ans;
}

// Bottom-up approach or Tabulation
int fibonacci(int n) {

    vector<int> dp(n, 0);

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <=n; i++) {

        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main() {

    int n = 4;
    vector<int> dp(n+1, -1); // size is n+1 because n+1 states are there(f(4), f(3),...f(0))

    cout << fibonacci(4);

    return 0;
}