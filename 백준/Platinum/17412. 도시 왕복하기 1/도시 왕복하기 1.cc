#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int,int>;

struct flow {
    struct edge {
        int from, to;
        int c, f = 0;
        int left() { return c - f; }

        edge(int from, int to, int c) {
            this->from = from;
            this->to = to;
            this->c = c;
        }
    };

    int n, m, s, t;
    vector<edge> E;
    vector<vector<int> > g;
    vector<int> level, see;

    flow(int n) {
        this->n = n;
        m = 0;
        g.resize(n);
        level.resize(n);
        see.resize(n);
    }

    void add_edge(int from, int to, int c) {
        E.push_back({from, to, c});
        E.push_back({to, from, 0});
        g[from].push_back(m);
        g[to].push_back(m + 1);
        m += 2;
    }

    bool bfs() { // find level graph
        fill(all(level), -1);
        queue<int> q;
        q.push(s);
        level[s] = 0;
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (int e: g[now]) {
                int next = E[e].to;
                if (E[e].left() > 0 && level[next] == -1) {
                    level[next] = level[now] + 1;
                    q.push(next);
                }
            }
        }
        return level[t] != -1;
    }

    int dfs(int now, int flow) { // flow along level graph
        if (now == t) return flow;

        for (int &i = see[now]; i < g[now].size(); i++) {
            int e = g[now][i];
            int next = E[e].to;
            if (E[e].left() > 0 && level[next] == level[now] + 1) {
                int f = dfs(next, min(E[e].left(), flow));
                if (f > 0) {
                    E[e].f += f;
                    E[e ^ 1].f -= f;
                    return f;
                }
            }
        }
        return 0; // no augmenting path
    }

    int maxflow(int s, int t) {
        this->s = s;
        this->t = t;

        int res = 0;
        while (bfs()) {
            fill(all(see), 0);
            while (int flow = dfs(s, 1e18)) res += flow;
        }
        return res;
    }
};

signed main() {
    int n, p;
    cin >> n >> p;
    flow graph(n + 1);
    while (p--) {
        int u, v;
        cin >> u >> v;
        graph.add_edge(u, v, 1);
    }
    cout << graph.maxflow(1, 2);
}
