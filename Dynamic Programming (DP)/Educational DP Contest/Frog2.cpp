#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> arr(n+1, 0);

    for(int i = 1; i <= n; i++) {
        
        cin >> arr[i];
    }

    vector<int> dp(n+1, INT_MAX);

    dp[1] = 0;
    dp[2] = abs(arr[2] - arr[1]);

    for(int i = 3; i <= n; i++) {

        for(int j = 1; j <= k; j++) {

            if(j >= i) break;
            dp[i] = min(dp[i], dp[i-j] + abs(arr[i] - arr[i-j]));
        }
    }

    cout << dp[n];

    return 0;
}