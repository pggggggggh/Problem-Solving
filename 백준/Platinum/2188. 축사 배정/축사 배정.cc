#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int,int>;

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > adj(n);
    for (int i = 0; i < n; i++) {
        int k, x;
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> x;
            x--;
            adj[i].push_back(x);
        }
    }
    vector<int> vis(n);
    vector<int> l(n, -1), r(m, -1);
    function<int(int)> dfs = [&](int v) {
        vis[v] = 1;
        for (auto &u: adj[v]) {
            if (r[u] == -1 || (!vis[r[u]] && dfs(r[u]))) {
                l[v] = u;
                r[u] = v;
                return 1;
            }
        }
        return 0;
    };
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (l[i] == -1) {
            fill(all(vis), 0);
            if (dfs(i)) res++;
        }
    }
    cout << res;
}
