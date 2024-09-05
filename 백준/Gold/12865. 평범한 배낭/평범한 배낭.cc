#include <bits/stdc++.h>
// #define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
using pi = pair<int, int>;

int dp[105][1000005]; // dp[i][j] : considered [0..i-1]

signed main() {
    int n, k;
    cin >> n >> k;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (i) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            if (i < n && j + w[i] <= k)
                dp[i + 1][j + w[i]] = max(dp[i + 1][j + w[i]], dp[i][j] + v[i]);
        }
    }
    cout << dp[n][k];
}
