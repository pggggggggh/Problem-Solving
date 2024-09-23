#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

signed main() {
  int n;
  cin >> n;
  vector<int> grundy(n + 1);
  grundy[1] = grundy[2] = grundy[3] = 1;
  for (int i = 4; i <= n; i++) {
    vector<int> vis(2000);
    for (int j = 1; j <= (i + 1) / 2; j++) {
      int tmp = grundy[i - (j + 2)];
      if (j - 3 >= 0) tmp ^= grundy[j - 3];
      vis[tmp] = 1;
    }
    while (vis[grundy[i]]) grundy[i]++;
  }
  cout << (1 + (grundy[n] == 0));
}