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
	vector<pi> v;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			pi p = { a[i].first + a[j].first, a[i].second + a[j].second };
			if (i == j) {
				v.push_back(p);
			} else {
				v.push_back(p);
				v.push_back(p);
			}
		}
	}
	sort(all(v));
	int ans = 0;
	int cur = 1;
	for (int i = 1; i < v.size(); i++) {
		if (v[i] == v[i - 1]) cur++;
		else {
			ans = max(ans, cur);
			cur = 1;
		}
	}
	ans = max(ans, cur);
	cout << ans;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}