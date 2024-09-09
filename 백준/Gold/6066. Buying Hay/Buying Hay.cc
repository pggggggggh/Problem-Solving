#include <bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
using pi = pair<int, int>;

signed main() {
    int n, h;
    cin >> n >> h;
    vector<array<int, 2> > a(n);
    for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
    sort(all(a), [&](array<int, 2> x, array<int, 2> y) {
        return x[1] * y[0] < x[0] * y[1];
    });
    vector<vector<int> > dp(n + 1, vector<int>(h + 1, 1e18));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= h; j++) {
            dp[i][min(h, j + a[i][0])] =
                    min(dp[i][min(h, j + a[i][0])], dp[i][j] + a[i][1]);
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
        }
    }

    cout << dp[n - 1][h];
}
