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

    vector<vector<int> > get_scc() {
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
                vector<int> c;
                while (1) {
                    int t = stk.top();
                    stk.pop();
                    sn[t] = scnt;
                    c.push_back(t);
                    if (t == v) break;
                }
                sort(all(c));
                scc.push_back(c);
                scnt++;
            }
            return res;
        };
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) dfs(i);
        }
        return scc;
    }
};

signed main() {
    int n, k;
    cin >> n >> k;
    strongly_connected g(n);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g.add_edge(x, y);
    }
    vector<vector<int> > scc = g.get_scc();
    sort(all(scc));
    cout << scc.size() << '\n';
    for (auto &c: scc) {
        sort(all(c));
        for (auto &x: c) cout << x + 1 << " ";
        cout << "-1 \n";
    }
}
