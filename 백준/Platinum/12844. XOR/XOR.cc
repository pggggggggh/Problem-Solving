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
        return a ^ b;
    }

    static L lazy_op(L a, L b) { // combine two lazy values
        return a ^ b;
    }

    static S apply_lazy(S s, L l, int len) {
        if (len & 1) return s ^ l;
        return s;
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
        seg[node] = apply_lazy(seg[node], lazy[node], r - l + 1);
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

    void apply(int x, int y, S val, int node, int l, int r) {
        propa(node, l, r);
        if (r < x || y < l) return;
        if (x <= l && r <= y) {
            lazy[node] = lazy_op(lazy[node], val);
            propa(node, l, r);
            return;
        }
        int mid = l + r >> 1;
        apply(x, y, val, node * 2, l, mid);
        apply(x, y, val, node * 2 + 1, mid + 1, r);
        seg[node] = seg_op(seg[node * 2], seg[node * 2 + 1]);
    }

    void apply(int x, int y, S val) {
        apply(x, y, val, 1, 0, sz - 1);
    }

    void apply(int x, S val) {
        apply(x, x, val);
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    lazyseg seg(n, a);
    cin >> q;
    while (q--) {
        int w, x, y, z;
        cin >> w >> x >> y;
        if (w == 1) {
            cin >> z;
            seg.apply(x, y, z);
        } else {
            cout << seg.query(x, y) << '\n';
        }
    }
}
