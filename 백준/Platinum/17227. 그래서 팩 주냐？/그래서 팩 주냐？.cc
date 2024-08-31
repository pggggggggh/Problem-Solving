#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int,int>;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > adj(n);
    vector<int> indegree(n);
    while (m--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        indegree[y]++;
    }
    vector<array<int, 2> > dp(n, {-1, -1});
    function<int(int,int)> dfs = [&](int v, int p) { // p=0 : 내가 여깄다
        int &ret = dp[v][p];
        if (ret != -1) return ret;
        if (v == n - 1) {
            if (p == 0) return 0LL;
            return (int) 1e15;
        }
        if (p == 1) {
            ret = 1e15;
            for (auto &u: adj[v]) {
                ret = min(ret, dfs(u, 0));
            }
        } else {
            vector<int> nxt;
            for (auto &u: adj[v]) {
                nxt.push_back(dfs(u, 1));
            }
            sort(all(nxt));
            ret = 1e15;
            for (auto &u: adj[v]) {
                int cur = dfs(u, 1);
                int num = nxt.end() - upper_bound(all(nxt), cur);
                ret = min(ret, cur + num);
            }
        }
        return ret;
    };
    int res = 1e15;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) res = min(res, dfs(i, 0));
    }
    cout << (res == 1e15 ? -1 : res);
}
