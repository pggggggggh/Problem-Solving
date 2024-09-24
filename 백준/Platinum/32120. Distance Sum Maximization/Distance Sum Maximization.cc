#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  auto bfs = [&](int s) {
    vector<int> dist(n + 1), vis(n + 1);
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      vis[u] = 1;
      q.pop();
      for (auto &v : adj[u]) {
        if (vis[v]) continue;
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
    return dist;
  };
  vector<int> dist0 = bfs(1);
  int v1 = max_element(all(dist0)) - dist0.begin();
  vector<int> dist1 = bfs(v1);
  int v2 = max_element(all(dist1)) - dist1.begin();
  vector<int> dist2 = bfs(v2);
  int mx = -1, v3;
  for (int i = 1; i <= n; i++) {
    if (dist1[i] + dist2[i] > mx) {
      mx = dist1[i] + dist2[i];
      v3 = i;
    }
  }
  vector<int> dist3 = bfs(v3);
  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    int res = 0;
    res = max(res, dist1[x] + dist1[y]);
    res = max(res, dist2[x] + dist2[y]);
    res = max(res, dist3[x] + dist3[y]);
    cout << res << '\n';
  }
}