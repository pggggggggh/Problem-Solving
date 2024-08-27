#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;

const int MOD = 10007;

int n;
int dp[1005] = {0, 1, 2};

signed main() {
    cin >> n;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    cout << dp[n];
}
