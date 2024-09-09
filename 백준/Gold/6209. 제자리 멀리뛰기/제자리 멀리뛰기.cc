#include <bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
using pi = pair<int, int>;

signed main() {
    int d, n, m;
    cin >> d >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a.push_back(d);
    sort(all(a));
    int lo = 0, hi = 1e18;
    while (lo + 1 < hi) {
        int mid = lo + hi >> 1;
        int cur = 0, cnt = 0;
        for (int i = 0; i < n + 1; i++) {
            if (a[i] - cur >= mid) {
                cur = a[i];
            } else {
                cnt++;
            }
        }
        if (cnt > m) hi = mid;
        else lo = mid;
    }
    cout << lo << '\n';
}
