#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  if (n == 1) {
    if (k == 1)
      cout << "0 1";
    else
      cout << "1 1";
    return 0;
  }
  vector<pi> a;
  a.push_back({0, 1});
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i / 2; j++) {
      if (gcd(i, j) != 1) continue;
      a.push_back({j, i});
    }
  }
  k--;
  // sort(all(a),
  //      [&](pi x, pi y) { return x.first * y.second < y.first * x.second; });
  if (k == a.size() - 1)
    cout << "1 2";
  else if (k >= a.size()) {
    int idx = 2 * (a.size() - 1) - k;
    nth_element(a.begin(), a.begin() + idx, a.end(), [&](pi x, pi y) {
      return x.first * y.second < y.first * x.second;
    });
    cout << a[idx].second - a[idx].first << ' ' << a[idx].second;
  } else {
    nth_element(a.begin(), a.begin() + k, a.end(), [&](pi x, pi y) {
      return x.first * y.second < y.first * x.second;
    });
    cout << a[k].first << ' ' << a[k].second;
  }
}