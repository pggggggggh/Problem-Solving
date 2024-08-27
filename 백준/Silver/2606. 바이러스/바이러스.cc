#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;

int vis[105];
vector<int> adj[105];

int dfs(int v) {
    int res = 1;
    vis[v] = 1;
    for (auto &u: adj[v]) {
        if (vis[u]) continue;
        res += dfs(u);
    }
    return res;
}

signed main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout << dfs(1) - 1;
}
