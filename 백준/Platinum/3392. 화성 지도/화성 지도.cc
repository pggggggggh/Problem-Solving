#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int,int>;

struct segtree {
    using S = pi;

    static constexpr S e = {0, 1};

    static S op(S a, S b) {
        if (a.first < b.first) return a;
        if (a.first > b.first) return b;
        return {a.first, a.second + b.second};
    }

    int n, sz;
    vector<S> seg;

    segtree(int n) {
        this->n = n;
        sz = 1;
        while (sz < n) sz *= 2;
        seg = vector(2 * sz, e);
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

    void update(int x, int val) {
        x += sz;
        seg[x].first += val;

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

    // /* only applicable in sum segtree */
    // int kth_element(int k) {
    //     int node = 1;
    //     while (node < sz) {
    //         if (seg[node * 2] < k) {
    //             k -= seg[node * 2];
    //             node = node * 2 + 1;
    //         } else node = node * 2;
    //     }
    //     return node - sz;
    // }
};

signed main() {
    int n;
    segtree seg(30005);
    vector<array<int, 4> > data;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        data.push_back({b, a, c, 1});
        data.push_back({d, a, c, -1});
    }
    sort(all(data));
    int res = 0;
    for (int i = 0; i < data.size(); i++) {
        const auto &[a,b,c,d] = data[i];
        for (int j = b; j < c; j++) seg.update(j, d);
        int width = seg.sz - seg.seg[1].second;
        if (i != data.size() - 1) res += (data[i + 1][0] - data[i][0]) * width;
    }
    cout << res;
}
