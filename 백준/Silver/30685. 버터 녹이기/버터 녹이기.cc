#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	vector<pi> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	sort(all(a));
	int res = 1e18;
	for (int i = 1; i < n; i++) {
		int l = (a[i - 1].second - 1) / 2;
		int r = (a[i].second - 1) / 2;
		int dist = a[i].first - a[i - 1].first - 1;
		if (dist >= l + r) continue;
		if (l <= dist / 2) res = min(res, dist - l);
		else if (r <= dist / 2) res = min(res, dist - r);
		else res = min(res, dist / 2);
	}
	if (res == 1e18) cout << "forever";
	else cout << res;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}