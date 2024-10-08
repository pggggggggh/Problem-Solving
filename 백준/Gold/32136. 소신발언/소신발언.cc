#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int,int>;

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    function<int(int)> f = [&](int x) {
        int res = 0;
        for (int i = 0; i < n; i++) res = max(res, abs(x - i) * a[i]);
        return res;
    };
    int lo = 0, hi = n - 1;
    while (lo + 5 < hi) {
        int p = (2 * lo + hi) / 3;
        int q = (lo + 2 * hi) / 3;
        if (f(p) <= f(q)) hi = q;
        else lo = p;
    }
    int res = f(lo);
    for (int i = lo + 1; i <= hi; i++) {
        res = min(res, f(i));
    }
    cout << res;
}
