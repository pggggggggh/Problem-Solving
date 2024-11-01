#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	vector<pi> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	map<pi, int> mp;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			pi p = { a[i].first + a[j].first, a[i].second + a[j].second };
			if (i == j) mp[p]++;
			else mp[p] += 2;
		}
	}
	int ans = 1;
	for (auto& [_, cnt] : mp) ans = max(ans, cnt);
	cout << ans;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}