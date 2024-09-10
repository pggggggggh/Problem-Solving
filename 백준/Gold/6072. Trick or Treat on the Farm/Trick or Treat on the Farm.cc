#include <bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
using pi = pair<int, int>;

vector<vector<int> > adj;
vector<set<int> > sadj;
vector<int> dfn, sn, stk;
vector<int> scc_sz;
vector<int> dp;
vector<int> self_loop;
int cnt;
int scnt;

int recur(int u) { // scc node
    int &res = dp[u];
    if (res != -1) return res;
    if (self_loop[u]) return res = 1;
    if (scc_sz[u] > 1) return res = scc_sz[u];

    res = 1e9;
    for (auto &v: sadj[u]) {
        res = min(res, recur(v) + 1);
    }
    return res;
}

int dfs(int u) {
    dfn[u] = ++cnt;
    stk.push_back(u);
    int up = dfn[u];
    for (auto &v: adj[u]) {
        if (dfn[v] == -1) up = min(up, dfs(v));
        else if (sn[v] == -1) up = min(up, dfn[v]);
    }
    if (up == dfn[u]) {
        int sz = 0;
        while (1) {
            int t = stk.back();
            stk.pop_back();
            sn[t] = scnt;
            sz++;
            if (t == u) break;
        }
        scc_sz.push_back(sz);
        scnt++;
    }
    return up;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    adj.resize(n + 1);
    dfn.resize(n + 1, -1);
    sn.resize(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        adj[i].push_back(x);
    }
    for (int i = 1; i <= n; i++) if (dfn[i] == -1) dfs(i);
    dp.resize(scnt, -1);
    sadj.resize(scnt);
    self_loop.resize(scnt);

    for (int u = 1; u <= n; u++) {
        for (auto &v: adj[u]) {
            if (sn[u] != sn[v]) {
                sadj[sn[u]].insert(sn[v]);
            }
            if (u == v) {
                self_loop[sn[u]] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << recur(sn[i]) << '\n';
}
