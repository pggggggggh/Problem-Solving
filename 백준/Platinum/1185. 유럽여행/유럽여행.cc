#include <bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
using pi = pair<int, int>;

struct edge {
    int s, e, x;
};

struct union_find {
    int n;
    vector<int> par;

    union_find(int n): n(n) {
        for (int i = 0; i < n; i++) par.push_back(i);
    }

    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void uni(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        par[y] = x;
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    vector<int> c(n);
    vector<edge> E(p);
    int mn = 1e9;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        mn = min(mn, c[i]);
    }
    for (int i = 0; i < p; i++) {
        int s, e, x;
        cin >> s >> e >> x;
        s--, e--;
        E.push_back({s, e, 2 * x + c[s] + c[e]});
    }
    int res = mn;
    union_find uf(n);
    sort(all(E), [&](edge &a, edge &b) {
        return a.x < b.x;
    });
    for (auto &[s,e,x]: E) {
        if (uf.find(s) != uf.find(e)) {
            uf.uni(s, e);
            res += x;
        }
    }
    cout << res;
}
