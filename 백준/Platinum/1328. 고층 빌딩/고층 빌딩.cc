#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int,int>;

int dp[105][105][105];

int32_t main() {
    int n, l, r;
    cin >> n >> l >> r;
    dp[1][1][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k <= i; k++) {
                dp[i][j][k] = (dp[i - 1][j][k] * (i - 2) + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1]) % ((int) 1e9 + 7);
            }
        }
    }
    cout << dp[n][l][r];
}
