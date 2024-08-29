#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int,int>;

struct lazyseg {
    static constexpr int seg_e = 0;

    static constexpr int lazy_e = 0;

    static int seg_op(int a, int b) {
        return a + b;
    }

    static int lazy_op(int a, int b) {
        return a ^ b;
    }

    static int lazy_comp(int a, int b) { // b times
        if (b & 1) return a;
        return lazy_e;
    }

    int n, sz;
    vector<int> seg;
    vector<int> lazy;

    lazyseg(int n) {
        this->n = n;
        sz = 1;
        while (sz < n) sz *= 2;
        seg = vector(2 * sz, seg_e);
        lazy = vector(2 * sz, lazy_e);
    }

    void propa(int node, int l, int r) {
        if (lazy[node] == lazy_e) return;
        if (lazy[node]) seg[node] = (r - l + 1) - seg[node];
        if (l != r) {
            lazy[node * 2] = lazy_op(lazy[node * 2], lazy[node]);
            lazy[node * 2 + 1] = lazy_op(lazy[node * 2 + 1], lazy[node]);
        }
        lazy[node] = lazy_e;
    }

    void set(int x, int val, int node, int l, int r) {
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

    void set(int x, int val) {
        set(x, val, 1, 0, sz - 1);
    }

    void apply(int x, int y, int val, int node, int l, int r) {
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

    void apply(int x, int y, int val) {
        apply(x, y, val, 1, 0, sz - 1);
    }

    void apply(int x, int val) {
        apply(x, x, val);
    }

    int query(int x, int y, int node, int l, int r) {
        propa(node, l, r);
        if (r < x || y < l) return seg_e;
        if (x <= l && r <= y) return seg[node];
        int mid = l + r >> 1;
        return seg_op(query(x, y, node * 2, l, mid), query(x, y, node * 2 + 1, mid + 1, r));
    }

    int query(int x, int y) {
        return query(x, y, 1, 0, sz - 1);
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    lazyseg seg(n + 1);
    while (k--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 0) seg.apply(x, y, 1);
        else cout << seg.query(x, y) << '\n';
    }
}
