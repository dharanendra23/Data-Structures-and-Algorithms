#include<bits/stdc++.h>
using namespace std;

// Memoization(Recursion logic + storage) or Top-down approach
int friendsParty(int n, vector<int> &dp) {

    if(n == 1 || n == 2) return n;

    if(dp[n] != -1) return dp[n]; // if already stored then return the value present at n
    int ans = friendsParty(n - 1, dp) + (n - 1) * friendsParty(n - 2, dp);
    dp[n] = ans; // storing

    return ans;
}

// Bottom-up approach or Tabulation
int friendsParty(int n) {

    vector<int> dp(n + 1, 0);

    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++) {

        dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    }

    return dp[n];
}

int main() {

    int n = 4;
    vector<int> dp(n + 1, -1);

    cout << friendsParty(n);

    return 0;
}