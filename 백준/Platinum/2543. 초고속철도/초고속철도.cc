#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define all(x) (x).begin(),(x).end()
#define MOD 20070713
using pi = pair<int, int>;

struct segtree {
    int n, sz;
    vector<int> seg;

    segtree(int n): n(n) {
        sz = 1;
        while (sz < n) sz *= 2;
        seg = vector<int>(2 * sz);
    }

    void put(int x, int val) {
        x += sz;
        seg[x] = val;
        while (x > 1) {
            x /= 2;
            seg[x] = (seg[x * 2] + seg[x * 2 + 1]) % MOD;
        }
    }

    int query(int l, int r) {
        int res = 0;
        l += sz, r += sz;
        for (; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) res = (res + seg[l++]) % MOD;
            if (!(r & 1)) res = (res + seg[r--]) % MOD;
        }
        return res;
    }
};

segtree seg(200005);

signed main() {
    int n;
    cin >> n;
    vector<pi> a(n);
    vector<int> sorted;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        sorted.push_back(a[i].first);
        sorted.push_back(a[i].second);
    }
    sort(all(a));
    sort(all(sorted));
    sorted.erase(unique(all(sorted)), sorted.end());
    vector<int> dp(n);
    int res = 0;
    for (int i = n - 1; i >= 0; i--) {
        int idx = lower_bound(all(sorted), a[i].second) - sorted.begin();
        dp[i] = (seg.query(idx, 200002) + 1) % MOD;
        res = (res + dp[i]) % MOD;
        int idx2 = lower_bound(all(sorted), a[i].first) - sorted.begin();
        seg.put(idx2, dp[i]);
    }
    cout << (res + 1) % MOD;
}
