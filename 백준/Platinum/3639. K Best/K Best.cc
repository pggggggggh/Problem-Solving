#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
#define double long double
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<array<int, 3>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1];
		a[i][2] = i;
	}
	double lo = 0, hi = 1e7 + 5;
	while (lo + 1e-7 < hi) {
		double mid = (lo + hi) / 2;
		sort(all(a), [&](array<int, 3>& a, array<int, 3>& b) {
			return a[0] - mid * a[1] > b[0] - mid * b[1];
		});
		double cur = 0;
		for (int i = 0; i < k; i++) cur += a[i][0] - mid * a[i][1];
		if (cur >= 0) lo = mid;
		else hi = mid;
	}
	// hi is the answer
	sort(all(a), [&](array<int, 3>& a, array<int, 3>& b) {
		return a[0] - hi * a[1] > b[0] - hi * b[1];
	});
	set<int> res;
	for (int i = 0; i < k; i++) res.insert(a[i][2]);
	for (auto& x : res) cout << x + 1 << ' ';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}