#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()

struct min_cost_max_flow {
    struct edge {
        int from, to;
        int c, f = 0;
        int cost;
        int left() { return c - f; }

        edge(int from, int to, int c, int cost): from(from), to(to), c(c), cost(cost) {
        }
    };

    int n, m, s, t;
    vector<edge> E;
    vector<vector<int> > g;
    vector<int> prev;

    min_cost_max_flow(int n) {
        this->n = n;
        m = 0;
        g.resize(n);
        prev.resize(n);
    }

    void add_edge(int from,int to, int c, int cost) {
        E.push_back({from, to, c, cost});
        E.push_back({to, from, 0, -cost});
        g[from].push_back(m);
        g[to].push_back(m + 1);
        m += 2;
    }

    bool spfa() {
        vector<int> dist(n, 1e18);
        vector<bool> inq(n, false);
        queue<int> q;

        fill(all(prev), -1);
        dist[s] = 0;
        q.push(s);
        inq[s] = true;

        while (!q.empty()) {
            int now = q.front();
            q.pop();
            inq[now] = false;
            for (auto &e: g[now]) {
                int next = E[e].to;
                if (E[e].left() > 0 && dist[now] + E[e].cost < dist[next]) {
                    dist[next] = dist[now] + E[e].cost;
                    prev[next] = e;

                    if (!inq[next]) {
                        q.push(next);
                        inq[next] = true;
                    }
                }
            }
        }
        return prev[t] != -1;
    }

    int mcmf(int s, int t) {
        this->s = s;
        this->t = t;

        int res = 0;
        while (spfa()) {
            int flow = 1e18;
            int e = prev[t];
            while (e != -1) {
                flow = min(flow, E[e].left());
                e = prev[E[e].from];
            }
            e = prev[t];
            while (e != -1) {
                res += flow * E[e].cost;
                E[e].f += flow;
                E[e ^ 1].f -= flow;
                e = prev[E[e].from];
            }
        }
        return res;
    }
};

signed main() {
    int n;
    cin >> n;
    min_cost_max_flow mcmf(2 * n + 2);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            mcmf.add_edge(i, j + n, 1e9, x);
        }
    }
    for (int i = 1; i <= n; i++) {
        mcmf.add_edge(0, i, 1, 0);
        mcmf.add_edge(i + n, 2 * n + 1, 1, 0);
    }
    cout << mcmf.mcmf(0, 2 * n + 1);
}
