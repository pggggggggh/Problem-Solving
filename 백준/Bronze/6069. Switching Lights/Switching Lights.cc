#include <bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
using pi = pair<int, int>;

struct lazyseg {
    int sz;
    vector<int> seg, lazy;

    lazyseg(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        seg.resize(2 * sz);
        lazy.resize(2 * sz);
    }

    void propa(int node, int l, int r) {
        if (lazy[node] == 0) return;
        seg[node] = (r - l + 1) - seg[node]; // lazy = 1
        if (l != r) {
            lazy[node * 2] ^= lazy[node];
            lazy[node * 2 + 1] ^= lazy[node];
        }
        lazy[node] = 0;
    }

    void flip(int x, int y, int node, int l, int r) {
        propa(node, l, r);
        if (y < l || r < x) return;
        if (x <= l && r <= y) {
            lazy[node] ^= 1;
            propa(node, l, r);
            return;
        }
        int mid = l + r >> 1;
        flip(x, y, node * 2, l, mid);
        flip(x, y, node * 2 + 1, mid + 1, r);
        seg[node] = seg[node * 2] + seg[node * 2 + 1];
    }

    void flip(int x, int y) {
        flip(x, y, 1, 0, sz - 1);
    }

    int query(int x, int y, int node, int l, int r) {
        propa(node, l, r);
        if (y < l || r < x) return 0;
        if (x <= l && r <= y) return seg[node];
        int mid = l + r >> 1;
        return query(x, y, node * 2, l, mid) + query(x, y, node * 2 + 1, mid + 1, r);
    }

    int query(int x, int y) {
        return query(x, y, 1, 0, sz - 1);
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    lazyseg seg(n + 1);
    while (m--) {
        int w, x, y;
        cin >> w >> x >> y;
        if (w == 0) {
            seg.flip(x, y);
        } else {
            cout << seg.query(x, y) << '\n';
        }
    }
}
