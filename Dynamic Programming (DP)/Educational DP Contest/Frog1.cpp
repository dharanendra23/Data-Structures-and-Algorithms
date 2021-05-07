#include<bits/stdc++.h>
using namespace std;

int frog(int n, vector<int> &arr, vector<int> &dp) {

    if(n == 1) return 0;
    if(n == 2) return abs(arr[n] - arr[n - 1]); 

    if(dp[n] != -1) return dp[n];

    int ans = min(abs(arr[n] - arr[n-1]) + frog(n - 1, arr, dp),  abs(arr[n] - arr[n-2]) + frog(n - 2, arr, dp));

    dp[n] = ans;

    return ans;
}

int main() {

    int n;
    cin >> n;

    vector<int> arr(n+1, 0);

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<int> dp(n+1, -1);

    cout << frog(n, arr, dp);

    // vector<int> dp(n+1, 0);

    // dp[1] = 0;
    // dp[2] = abs(arr[2] - arr[1]);

    // for(int i = 3; i <= n; i++) {

    //     dp[i] = min(dp[i-1] + abs(arr[i] - arr[i-1]), dp[i-2] + abs(arr[i] - arr[i-2]));
    // }

    // cout << dp[n];

    return 0;
}