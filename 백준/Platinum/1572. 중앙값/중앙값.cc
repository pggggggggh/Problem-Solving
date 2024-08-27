#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;

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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    segtree tree(70000);
    cin >> n >> k;
    vector<int> a(n + 1);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tree.add(a[i], 1);
        if (i >= k) {
            res += tree.kth_element((k + 1) / 2);
            tree.add(a[i - k + 1], -1);
        }
    }
    cout << res;
}
