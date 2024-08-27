#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;

struct eulerian_directed {
    struct edge {
        int from, to;
    };

    int n, m;
    vector<edge> edges;
    vector<vector<int> > g;
    vector<int> in, out;

    eulerian_directed(int n) {
        this->n = n;
        this->m = 0;
        g.resize(n);
        in.resize(n);
        out.resize(n);
    }

    void add_edge(int from, int to) {
        edges.push_back({from, to});
        g[from].push_back(m);
        out[from]++;
        in[to]++;
        m++;
    }

    vector<int> euler_walk(int _s) {
        int flag = 1;
        int s = -1, e = -1;
        for (int i = 0; i < n; i++) {
            if (abs(out[i] - in[i]) > 1) return vector<int>();
            if (out[i] != in[i]) flag = 0;
            if (out[i] - in[i] == 1) {
                if (s == -1) s = i;
                else return vector<int>();
            }
            if (in[i] - out[i] == 1) {
                if (e == -1) e = i;
                else return vector<int>();
            }
        }
        if (!flag && s != _s) return vector<int>();
        s = _s;

        vector<int> res;
        vector<int> see(n), vis(m);
        auto dfs = [&](auto &&self, int v) -> void {
            for (auto &i = see[v]; i < g[v].size(); i++) {
                int &e = g[v][i];
                if (vis[e]) continue;
                vis[e] = 1;
                self(self, edges[e].to);
            }
            res.push_back(v);
        };
        dfs(dfs, s);
        reverse(all(res));
        return res;
    }
};

signed main() {
    int n;
    cin >> n;
    eulerian_directed graph(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph.add_edge(i, j);
        }
    }
    vector<int> res = graph.euler_walk(1);
    cout << res.size() << '\n';
    for (auto &x: res) cout << x << " ";
}
