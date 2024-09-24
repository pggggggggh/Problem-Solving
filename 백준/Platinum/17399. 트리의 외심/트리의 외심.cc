#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

const int MAX_LOG = 18;

int par[100005][MAX_LOG];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  vector<int> dep(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  function<void(int, int)> dfs = [&](int u, int p) {
    for (auto &v : adj[u]) {
      if (v == p) continue;
      par[v][0] = u;
      dep[v] = dep[u] + 1;
      dfs(v, u);
    }
  };
  dfs(1, -1);
  for (int i = 1; i < MAX_LOG; i++) {
    for (int j = 1; j <= n; j++) {
      par[j][i] = par[par[j][i - 1]][i - 1];
    }
  }
  auto parent_k = [&](int u, int k) {
    for (int i = MAX_LOG - 1; i >= 0; i--) {
      if ((k >> i) & 1) u = par[u][i];
    }
    return u;
  };
  auto lca = [&](int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int diff = dep[u] - dep[v];
    u = parent_k(u, diff);
    if (u == v) return u;
    for (int i = MAX_LOG - 1; i >= 0; i--) {
      if (par[u][i] == par[v][i]) continue;
      u = par[u][i], v = par[v][i];
    }
    return par[u][0];
  };
  auto distance = [&](int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
  };
  int q;
  cin >> q;
  while (q--) {
    array<int, 3> a;
    cin >> a[0] >> a[1] >> a[2];
    int res = -1;
    for (int i = 0; i < 3; i++) {
      for (int j = i + 1; j < 3; j++) {
        int k = 3 - (i + j);
        int dist = distance(a[i], a[j]);
        if (dist % 2) continue;
        int deeper = dep[a[i]] > dep[a[j]] ? a[i] : a[j];
        int mid = parent_k(deeper, dist / 2);
        if (distance(mid, a[k]) == dist / 2) {
          res = mid;
          break;
        }
      }
    }
    cout << res << '\n';
  }
}
