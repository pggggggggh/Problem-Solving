#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int,int>;

int n, m;
int a[4005];
int dp[4005][4005];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i * 2];
    for (int i = 0; i < n * 2; i++) {
        for (int j = 0; j <= min(i, 2 * n - i - 1); j++) {
            if (a[i + j] != a[i - j]) break;
            dp[i][j] = 1;
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x = (x - 1) * 2, y = (y - 1) * 2;
        cout << dp[(x + y) / 2][(y - x) / 2] << '\n';
    }
}
