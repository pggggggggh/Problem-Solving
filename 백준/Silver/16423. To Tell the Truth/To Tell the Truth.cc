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
	for (int i = n; i >= 0; i--) {
		int cur = 0;
		for (int j = 0; j < n; j++) {
			if (a[j].first <= i && i <= a[j].second) cur++;
		}
		if (cur == i) {
			cout << i;
			return;
		}
	}
	cout << -1;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}