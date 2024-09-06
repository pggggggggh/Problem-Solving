#include <bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
using pi = pair<int, int>;

struct union_find {
    int n;
    vector<int> par, sz;

    union_find(int n): n(n) {
        par.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void uni(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        par[y] = x;
        sz[x] += sz[y];
    }
};

struct edge {
    int s, e, x;
};

signed main() {
    int n, m, q;
    cin >> n >> m;
    vector<edge> E(m);
    for (int i = 0; i < m; i++) cin >> E[i].s >> E[i].e >> E[i].x;
    sort(all(E), [&](edge a, edge b) -> int {
        return a.x < b.x;
    });
    cin >> q;
    vector<pi> Q(q);
    vector<int> lo(q, 0), hi(q, m + 1);
    vector<pi> res(q);
    for (int i = 0; i < q; i++) cin >> Q[i].first >> Q[i].second;
    while (1) {
        vector<vector<int> > g(100005);
        int flag = 0;
        for (int i = 0; i < q; i++) {
            if (lo[i] + 1 < hi[i]) {
                flag = 1;
                g[(lo[i] + hi[i]) / 2].push_back(i);
            }
        }
        if (!flag) break;

        union_find uf(n + 1);
        for (int i = 0; i < m; i++) {
            auto [s,e,x] = E[i];
            uf.uni(s, e);

            int mid = i + 1;
            for (auto &j: g[mid]) {
                if (uf.find(Q[j].first) == uf.find(Q[j].second)) {
                    hi[j] = mid;
                    res[j].first = x;
                    res[j].second = uf.sz[uf.find(Q[j].first)];
                } else lo[j] = mid;
            }
        }
    }
    for (int i = 0; i < q; i++) {
        if (lo[i] == m) cout << -1 << '\n';
        else cout << res[i].first << ' ' << res[i].second << '\n';
    }
}
