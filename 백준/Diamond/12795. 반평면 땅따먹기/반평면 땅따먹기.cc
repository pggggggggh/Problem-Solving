#include <bits/stdc++.h>
#define aint(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int,int>;

struct Line {
    mutable int k, m, p;
    bool operator<(const Line &o) const { return k < o.k; }
    bool operator<(int x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<> > {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    static constexpr int inf = 1e18;

    static int div(int a, int b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b);
    }

    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = inf, 0;
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }

    void add(int k, int m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }

    int query(int x) {
        assert(!empty());
        auto [k, m, p] = *lower_bound(x);
        return k * x + m;
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    LineContainer lc;
    while (q--) {
        int w, x, y;
        cin >> w >> x;
        if (w == 1) {
            cin >> y;
            lc.add(x, y);
        } else cout << lc.query(x) << '\n';
    }
}
