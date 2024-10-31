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
	map<pi, int> mp[4];
	int horpos = 0, horneg = 0, verpos = 0, verneg = 0;
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	for (int i = 0; i < n; i++) {
		if (a[i].first == 0) {
			if (a[i].second > 0) horpos++;
			else horneg++;
			continue;
		}
		if (a[i].second == 0) {
			if (a[i].first > 0) verpos++;
			else verneg++;
			continue;
		}
		int g = gcd(abs(a[i].first), abs(a[i].second));
		pi p = { abs(a[i].first) / g, abs(a[i].second) / g };
		mp[(a[i].first > 0) * 2 + (a[i].second > 0)][p]++;
	}
	int res = max({ horpos, horneg, verpos, verneg });
	for (int i = 0; i < 4; i++) {
		for (auto& [_, num] : mp[i]) res = max(res, num);
	}
	cout << res;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}