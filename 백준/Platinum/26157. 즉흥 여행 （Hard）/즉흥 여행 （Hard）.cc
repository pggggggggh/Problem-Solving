#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int,int>;

struct strongly_connceted {
    int n;
    vector<set<int> > adj;

    strongly_connceted(int n) {
        this->n = n;
        adj.resize(n);
    }

    void add_edge(int from, int to) {
        adj[from].insert(to);
    }

    vector<int> get_scc() {
        vector<int> dfn(n, -1);
        vector<int> sn(n, -1);
        int cnt = 0, scnt = 0;
        stack<int> stk;
        function<int(int)> dfs = [&](int v) {
            dfn[v] = ++cnt;
            stk.push(v);
            int res = dfn[v];
            for (auto &u: adj[v]) {
                if (dfn[u] == -1) res = min(res, dfs(u));
                else if (sn[u] == -1) res = min(res, dfn[u]);
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

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    strongly_connceted scc(n);
    vector<pi> E;
    while (m--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        E.push_back({x, y});
        scc.add_edge(x, y);
    }
    auto sn = scc.get_scc();
    int sccn = *max_element(all(sn)) + 1;
    vector<set<int> > sadj(sccn);
    vector<int> sindegree(sccn);
    for (auto &[x,y]: E) {
        if (sn[x] != sn[y]) {
            sadj[sn[x]].insert(sn[y]);
            sindegree[sn[y]]++;
        }
    }
    int s = -1;
    for (int i = 0; i < sccn; i++) {
        if (sindegree[i] == 0) {
            if (s != -1) {
                cout << 0;
                return 0;
            }
            s = i;
        }
    }
    assert(s != -1);
    vector<int> dp(sccn, -1);
    function<int(int)> recur = [&](int v) -> int {
        int &ret = dp[v];
        if (ret != -1) return ret;
        ret = 0;
        for (auto &u: sadj[v]) {
            ret = max(ret, recur(u));
        }
        ret++;
        return ret;
    };
    if (recur(s) != sccn) cout << '0';
    else {
        vector<int> res;
        for (int i = 0; i < n; i++) if (sn[i] == sccn - 1) res.push_back(i + 1);
        cout << res.size() << '\n';
        for (auto &x: res) cout << x << ' ';
    }
}
