#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int,int>;

struct bcc {
    int n;
    vector<vector<int> > adj;

    bcc(int n) {
        this->n = n;
        adj.resize(n);
    }

    void add_edge(int from,int to) { // undirected
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    vector<set<int> > get_bcc() {
        vector<int> dfn(n, -1);
        vector<set<int> > bn(n);
        int cnt = 0, bcnt = 0;
        stack<pi> stk;
        function<int(int,int)> dfs = [&](int v, int p) {
            dfn[v] = ++cnt;
            int res = dfn[v];
            for (auto &u: adj[v]) {
                if (u == p) continue;
                if (dfn[v] > dfn[u]) stk.push({v, u});
                if (dfn[u] != -1) res = min(res, dfn[u]);
                else {
                    int low = dfs(u, v);
                    res = min(res, low);
                    if (low >= dfn[v]) {
                        // articulation edge
                        while (1) {
                            auto [vv,uu] = stk.top();
                            stk.pop();
                            bn[vv].insert(bcnt);
                            bn[uu].insert(bcnt);
                            if (vv == v && uu == u) break;
                        }
                        bcnt++;
                    }
                }
            }
            return res;
        };
        for (int i = 0; i < n; i++) if (dfn[i] == -1) dfs(i, 0);
        return bn;
    }
};

signed main() {
    int n, m;
    cin >> n >> m;
    bcc bcc(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        bcc.add_edge(x, y);
    }
    auto bn = bcc.get_bcc();
    vector<int> cut;
    for (int i = 0; i < n; i++) {
        if (bn[i].size() > 1) cut.push_back(i);
    }
    cout << cut.size() << '\n';
    for (auto &x: cut) cout << x + 1 << ' ';
}
