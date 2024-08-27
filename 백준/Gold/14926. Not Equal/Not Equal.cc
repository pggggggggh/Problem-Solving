#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
// #define int long long
using namespace std;

struct eulerian {
    struct edge {
        int from, to;
    };

    int n, m;
    vector<edge> edges;
    vector<vector<int> > g;
    vector<int> degree;

    eulerian(int n) {
        this->n = n;
        this->m = 0;
        g.resize(n);
        degree.resize(n);
    }

    void add_edge(int from, int to) {
        edges.push_back({from, to});
        edges.push_back({to, from});
        g[from].push_back(m);
        g[to].push_back(m + 1);
        degree[from]++;
        degree[to]++;
        m += 2;
    }

    vector<int> euler_walk(int s) { // returns empty vector when impossible
        for (int i = 0; i < n; i++) if (degree[i] % 2) return vector<int>();
        vector<int> res;
        vector<int> see(n), vis(edges.size());
        auto dfs = [&](auto &&self, int v) -> void {
            for (int &i = see[v]; i < g[v].size(); i++) {
                int &e = g[v][i];
                if (vis[e]) continue;
                vis[e] = vis[e ^ 1] = 1;
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
    eulerian graph(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            graph.add_edge(i, j);
        }
    }
    vector<int> res = graph.euler_walk(0);
    for (auto &x: res) cout << "a" << x + 1 << " ";
}
