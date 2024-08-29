#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int,int>;

struct lazyseg {
    static constexpr int e = 0;

    static int op(int a, int b) {
        return a + b;
    }

    static int comp(int a, int b) { // b times
        return a * b;
    }

    int sz;
    vector<int> seg;
    vector<int> lazy;

    lazyseg(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        seg = vector(2 * sz, e);
        lazy = vector(2 * sz, e);
    }

    void propa(int node, int l, int r) {
        if (lazy[node] == 0) return;
        seg[node] = op(seg[node], comp(lazy[node], r - l + 1));
        if (l != r) {
            lazy[node * 2] = op(lazy[node * 2], lazy[node]);
            lazy[node * 2 + 1] = op(lazy[node * 2 + 1], lazy[node]);
        }
        lazy[node] = e;
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
        seg[node] = op(seg[node * 2], seg[node * 2 + 1]);
    }

    void set(int x, int val) {
        set(x, val, 1, 0, sz - 1);
    }

    void apply(int x, int y, int val, int node, int l, int r) {
        propa(node, l, r);
        if (r < x || y < l) return;
        if (x <= l && r <= y) {
            lazy[node] = op(lazy[node], val);
            propa(node, l, r);
            return;
        }
        int mid = l + r >> 1;
        apply(x, y, val, node * 2, l, mid);
        apply(x, y, val, node * 2 + 1, mid + 1, r);
        seg[node] = op(seg[node * 2], seg[node * 2 + 1]);
    }

    void apply(int x, int y, int val) {
        apply(x, y, val, 1, 0, sz - 1);
    }

    void apply(int x, int val) {
        apply(x, x, val);
    }

    int query(int x, int y, int node, int l, int r) {
        propa(node, l, r);
        if (r < x || y < l) return e;
        if (x <= l && r <= y)return seg[node];
        int mid = l + r >> 1;
        return op(query(x, y, node * 2, l, mid), query(x, y, node * 2 + 1, mid + 1, r));
    }

    int query(int x, int y) {
        return query(x, y, 1, 0, sz - 1);
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    lazyseg seg(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        seg.set(i, x);
    }
    for (int i = 0; i < m + k; i++) {
        int w, x, y, z;
        cin >> w >> x >> y;
        if (w == 1) {
            cin >> z;
            seg.apply(x, y, z);
        } else cout << seg.query(x, y) << '\n';
    }
}
