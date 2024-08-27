#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;

int n, m;
char a[55][55];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 1e9;
    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {
            int cnt = 0;
            for (int k = i; k < i + 8; k++) {
                for (int l = j; l < j + 8; l++) {
                    if ((k + l) % 2 == (a[k][l] == 'W')) cnt++;
                }
            }
            ans = min(ans, min(64 - cnt, cnt));
        }
    }
    cout << ans;
}
