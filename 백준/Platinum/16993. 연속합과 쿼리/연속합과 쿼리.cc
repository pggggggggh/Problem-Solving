#include <bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
using pi = pair<int, int>;

struct segtree {
    using S = struct node {
        int lmx, rmx, mx, sum;

        node(int val = -1e9) {
            lmx = rmx = mx = sum = val;
        }
    };
    S e = node();

    S op(S l, S r) {
        node res;
        res.lmx = max(l.lmx, l.sum + r.lmx);
        res.rmx = max(r.rmx, r.sum + l.rmx);
        res.mx = max({l.mx, r.mx, l.rmx + r.lmx});
        res.sum = l.sum + r.sum;
        return res;
    }

    int n, sz;
    vector<S> seg;

    segtree(int n, const vector<S> &v = vector<S>()) {
        assert(n >= v.size());
        this->n = n;
        sz = 1;
        while (sz < n) sz *= 2;
        seg = vector(2 * sz, e);
        for (int i = 0; i < v.size(); i++) seg[i + sz] = v[i];
        for (int i = sz - 1; i >= 1; i--) seg[i] = op(seg[i * 2], seg[i * 2 + 1]);
    }

    void put(int x, const S &val) {
        x += sz;
        seg[x] = val;
        while (x > 1) {
            x /= 2;
            seg[x] = op(seg[x * 2], seg[x * 2 + 1]);
        }
    }

    void add(int x, const S &val) {
        x += sz;
        seg[x] = op(seg[x], val);

        while (x > 1) {
            x /= 2;
            seg[x] = op(seg[x * 2], seg[x * 2 + 1]);
        }
    }

    S query(int l, int r) {
        S res_l, res_r;
        l += sz, r += sz;
        for (; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) res_l = op(res_l, seg[l++]);
            if (!(r & 1)) res_r = op(seg[r--], res_r);
        }
        return op(res_l, res_r);
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    segtree seg(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        seg.put(i, x);
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << seg.query(x, y).mx << '\n';
    }
}
