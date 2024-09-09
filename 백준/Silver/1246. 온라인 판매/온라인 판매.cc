#include <bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
using pi = pair<int, int>;


signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];
    sort(all(a), greater<int>());
    int res = 0;
    int res2 = 0;
    for (int i = 0; i < m; i++) {
        int cur = a[i] * min(i + 1, n);
        if (cur > res) {
            res = cur;
            res2 = a[i];
        }
    }
    cout << res2 << ' ' << res;
}
