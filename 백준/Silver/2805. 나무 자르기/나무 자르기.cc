#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int,int>;

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int lo = 0, hi = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        hi = max(hi, a[i]);
    }
    function<int(int)> able = [&](int x) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < x) continue;
            res += a[i] - x;
        }
        return res >= m;
    };
    while (lo + 1 < hi) {
        int mid = lo + hi >> 1;
        if (able(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo;
}
