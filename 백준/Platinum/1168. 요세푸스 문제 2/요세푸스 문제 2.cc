#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int,int>;

struct segtree {
    static constexpr int e = 0;

    static int op(int a, int b) {
        return a + b;
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

    void add(int x, int val) {
        x += sz;
        seg[x] += val;
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

    // only applicable in sum segtree
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
    int n, k;
    cin >> n >> k;
    segtree seg(n + 1);
    for (int i = 1; i <= n; i++) seg.set(i, 1);
    int pos = k;
    vector<int> ans;
    while (n) {
        pos %= n;
        if (pos == 0) pos = n;
        vector<int> del;
        for (int i = pos; i <= n; i += k) del.push_back(seg.kth_element(i));
        for (auto &d: del) {
            ans.push_back(d);
            seg.set(d, 0);
        }
        pos = k - (n - pos) % k;
        n -= del.size();
    }
    cout << '<';
    for (auto &a: ans) {
        cout << a;
        if (a != ans.back()) cout << ", ";
    }
    cout << '>';
}
