#include<bits/stdc++.h>
using namespace std;

int main() {

    long n, w;
    cin >> n >> w;

    vector<vector<long long> > dp(n + 1, vector<long long> (w + 1, 0));

    vector<long long> wt(n+1, 0);
    vector<long long> v(n+1, 0);

    for(int i = 1; i <= n; i++) {

        cin >> wt[i] >> v[i];
    }

    for(int i = 0; i <= n; i++) {

        for(int j = 0; j <= w; j++) {

            if(i == 0 || j == 0) {

                dp[i][j] = 0;
            }
            else if(j < wt[i]) {

                dp[i][j] = dp[i-1][j];
            }else {

                dp[i][j] = max(v[i] + dp[i-1][j - wt[i]], dp[i-1][j]);
            }
        }
    }

    cout << dp[n][w];

    return 0;
}