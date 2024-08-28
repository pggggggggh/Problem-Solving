#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;

int n, k;

struct strongly_connected {
    int n;
    vector<vector<int> > adj;

    strongly_connected(int n) {
        this->n = n;
        adj.resize(n);
    }

    void add_edge(int from,int to) {
        adj[from].push_back(to);
    }

    vector<int> get_scc() {
        vector<int> dfn(n, -1);
        vector<int> sn(n, -1);
        vector<vector<int> > scc;
        int cnt = 0, scnt = 0;
        stack<int> stk;
        function<int(int)> dfs = [&](int v) {
            dfn[v] = ++cnt;
            stk.push(v);
            int res = dfn[v];
            for (auto &u: adj[v]) {
                if (dfn[u] == -1) res = min(res, dfs(u)); // not visited
                else if (sn[u] == -1) res = min(res, dfn[u]); // visited, but not finished
            }
            if (res == dfn[v]) {
                while (1) {
                    int t = stk.top();
                    stk.pop();
                    sn[t] = scnt;
                    if (t == v) break;
                }
                scnt++;
            }
            return res;
        };
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) dfs(i);
        }
        return sn;
    }
};

struct twosat {
    int n;
    strongly_connected scc;
    vector<int> sn;

    twosat(int n): n(n), scc(2 * n + 2) {
    }

    void add_edge(int x, int y) {
        // usage : 1~n for true, -n~-1 for false
        if (x < 0) x = (-x) << 1 | 1;
        else x = x << 1;
        if (y < 0) y = (-y) << 1 | 1;
        else y = y << 1;
        scc.add_edge(x ^ 1, y);
        scc.add_edge(y ^ 1, x);
    }

    bool satisfy() {
        sn = scc.get_scc();
        for (int i = 1; i <= n; i++) if (sn[i << 1] == sn[i << 1 | 1]) return false;
        return true;
    }

    vector<bool> get_solution() {
        if (!satisfy()) return vector<bool>();
        vector<bool> res(n + 1, false);

        for (int i = 1; i <= n; i++) if (sn[i << 1] < sn[i << 1 | 1]) res[i] = true;
        return res;
    }
};

signed main() {
    int n, m;
    cin >> n >> m;
    twosat twosat(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        twosat.add_edge(x, y);
    }
    vector<bool> sol = twosat.get_solution();
    if (sol.empty()) {
        cout << 0;
        return 0;
    }
    cout << 1 << '\n';
    for (int i = 1; i <= n; i++) {
        cout << sol[i] << ' ';
    }
}
