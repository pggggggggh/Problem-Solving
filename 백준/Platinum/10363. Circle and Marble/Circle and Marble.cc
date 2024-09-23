#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve() {
  int n;
  cin >> n;
  vector<int> marbles(n + 1), grundy(n + 1);
  vector<vector<int>> adj(n + 1), g(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> marbles[i];
  }
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x == 0) continue;
    adj[i].push_back(x);
    adj[x].push_back(i);
  }
  vector<int> order;
  function<void(int, int)> dfs_tree = [&](int u, int p) {
    order.push_back(u);
    for (auto &v : adj[u]) {
      if (v == p) continue;
      g[u].push_back(v);
      dfs_tree(v, u);
    }
  };
  dfs_tree(1, -1);
  reverse(all(order));
  for (auto &u : order) {
    vector<int> vis(g[u].size());
    for (auto &v : g[u]) {
      if (grundy[v] < g[u].size()) vis[grundy[v]] = 1;
    }
    for (int i = 0; i < g[u].size(); i++) {
      if (vis[i] == 0) break;
      grundy[u]++;
    }
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (marbles[i] % 2) res ^= grundy[i];
  }
  if (res)
    cout << "first\n";
  else
    cout << "second\n";
}

signed main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}