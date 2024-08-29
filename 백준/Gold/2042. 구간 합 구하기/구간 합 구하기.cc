#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int,int>;

struct segtree {
    using S = int;

    static constexpr S e = 0;

    static S op(S a, S b) {
        return a + b;
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

    void set(int x, const S &val) {
        x += sz;
        seg[x] = val;
        while (x > 1) {
            x /= 2;
            seg[x] = op(seg[x * 2], seg[x * 2 + 1]);
        }
    }

    void update(int x, const S &val) {
        x += sz;
        seg[x] = op(seg[x], val);

        while (x > 1) {
            x /= 2;
            seg[x] = op(seg[x * 2], seg[x * 2 + 1]);
        }
    }

    S query(int l, int r) {
        S res = e;
        l += sz, r += sz;
        for (; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) res = op(res, seg[l++]);
            if (!(r & 1)) res = op(res, seg[r--]);
        }
        return res;
    }

    /* only applicable in int/sum segtree */
    int kth_element(int k) {
        int node = 1;
        while (node < sz) {
            if (seg[node * 2] < k) {
                k -= seg[node * 2];
                node = node * 2 + 1;
            } else node = node * 2;
        }
        return node - sz;
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    segtree seg(n, a);
    for (int i = 0; i < m + k; i++) {
        int w, x, y;
        cin >> w >> x >> y;
        if (w == 1) seg.set(x - 1, y);
        else cout << seg.query(x - 1, y - 1) << '\n';
    }
}
