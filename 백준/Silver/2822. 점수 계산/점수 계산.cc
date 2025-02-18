#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n = 8;
	vector<pi> a;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a.push_back({ x, i });
	}
	sort(all(a), greater<pi>());
	vector<int> v;
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		v.push_back(a[i].second);
		sum += a[i].first;
	}
	sort(all(v));
	cout << sum << '\n';
	for (auto& x : v) cout << x << ' ';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}