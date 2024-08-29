#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int,int>;

struct lazyseg {
    using S = int;

    using L = int;

    static constexpr S seg_e = 0; // identity of seg_op

    static constexpr L lazy_e = 0; // identity of lazy_op

    static S seg_op(S a, S b) { // combine two nodes
        return a + b;
    }

    static L lazy_op(L a, L b) { // combine two lazy values
        return a + b;
    }

    static void apply_lazy(S &s, L l, int len) {
        s += l * len;
    }

    int n, sz;
    vector<S> seg;
    vector<L> lazy;

    lazyseg(int n) {
        this->n = n;
        sz = 1;
        while (sz < n) sz *= 2;
        seg = vector(2 * sz, seg_e);
        lazy = vector(2 * sz, lazy_e);
    }

    lazyseg(int n, vector<S> v) : lazyseg(n) {
        assert(n >= v.size());
        for (int i = 0; i < v.size(); i++) {
            seg[i + sz] = v[i];
        }
        for (int i = sz - 1; i >= 1; i--) seg[i] = seg_op(seg[i * 2], seg[i * 2 + 1]);
    }

    void propa(int node, int l, int r) {
        if (lazy[node] == lazy_e) return;
        apply_lazy(seg[node], lazy[node], r - l + 1);
        if (l != r) {
            lazy[node * 2] = lazy_op(lazy[node * 2], lazy[node]);
            lazy[node * 2 + 1] = lazy_op(lazy[node * 2 + 1], lazy[node]);
        }
        lazy[node] = lazy_e;
    }

    void set(int x, S val, int node, int l, int r) {
        propa(node, l, r);
        if (l == r) {
            seg[node] = val;
            return;
        }
        int mid = l + r >> 1;
        if (x <= mid) set(x, val, node * 2, l, mid);
        else set(x, val, node * 2 + 1, mid + 1, r);
        seg[node] = seg_op(seg[node * 2], seg[node * 2 + 1]);
    }

    void set(int x, S val) {
        set(x, val, 1, 0, sz - 1);
    }

    void update(int x, int y, S val, int node, int l, int r) {
        propa(node, l, r);
        if (r < x || y < l) return;
        if (x <= l && r <= y) {
            lazy[node] = lazy_op(lazy[node], val);
            propa(node, l, r);
            return;
        }
        int mid = l + r >> 1;
        update(x, y, val, node * 2, l, mid);
        update(x, y, val, node * 2 + 1, mid + 1, r);
        seg[node] = seg_op(seg[node * 2], seg[node * 2 + 1]);
    }

    void update(int x, int y, S val) {
        update(x, y, val, 1, 0, sz - 1);
    }

    S query(int x, int y, int node, int l, int r) {
        propa(node, l, r);
        if (r < x || y < l) return seg_e;
        if (x <= l && r <= y) return seg[node];
        int mid = l + r >> 1;
        return seg_op(query(x, y, node * 2, l, mid), query(x, y, node * 2 + 1, mid + 1, r));
    }

    S query(int x, int y) {
        return query(x, y, 1, 0, sz - 1);
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n;
    lazyseg lazy(n + 2);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        lazy.set(i, a[i] - a[i - 1]);
    }
    cin >> q;
    while (q--) {
        int w, x, y;
        cin >> w >> x;
        if (w == 1) {
            cin >> y;
            lazy.update(x, y, 1);
            lazy.update(y + 1, y + 1, -(y - x + 1));
        } else {
            cout << lazy.query(1, x) << '\n';
        }
    }
}
