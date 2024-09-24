#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

int n;
array<int, 4> a[5005];
vector<pi> adj[5005];
int dp[5005];

int recur(int u) {
  int &ret = dp[u];
  if (ret != -1) return ret;
  ret = 0;
  for (auto &[v, see] : adj[u]) {
    ret = max(ret, see + recur(v));
  }
  return ret;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  a[0] = {0, 0, 0, 0};
  for (int i = 1; i <= n; i++) {
    cin >> a[i][0] >> a[i][1];
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i][2] >> a[i][3];
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (j == i) continue;
      int dist = abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1]);
      int arrive = a[i][3] + dist;
      if (arrive > a[j][3]) continue;
      int see = a[j][3] - max(arrive, a[j][2]);
      adj[i].push_back({j, see});
    }
  }
  memset(dp, -1, sizeof(dp));
  cout << recur(0);
}