#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;

struct segtree {
    static constexpr int e = 1e9;

    static int op(int a, int b) {
        return min(a, b);
    }

    int sz;
    vector<int> seg;

    segtree(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        seg = vector(2 * sz, e);
    }

    void set(int x, int val) {
        x += sz;
        seg[x] = val;
        while (x > 1) {
            x /= 2;
            seg[x] = op(seg[x * 2], seg[x * 2 + 1]);
        }
    }

    int query(int l, int r) {
        int res = e;
        l += sz, r += sz;
        for (; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) res = op(res, seg[l++]);
            if (!(r & 1)) res = op(res, seg[r--]);
        }
        return res;
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int, 3> > a(n + 1);
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            a[x][i] = j;
        }
    }
    sort(all(a));
    segtree rmq(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i][2] <= rmq.query(1, a[i][1])) ans++;
        rmq.set(a[i][1], a[i][2]);
    }
    cout << ans;
}
