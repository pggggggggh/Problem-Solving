#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

double intersect(pi a, pi b)
{
	return (double)(b.second - a.second) / (double)(a.first - b.first);
}

void solve()
{
	int n;
	cin >> n;
	vector<int> a(1);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x == 1) a.push_back(i);
	}
	int m = a.size() - 1;
	vector<int> ldp(m + 2, 1e18), rdp(m + 2, 1e18);
	ldp[0] = 0;
	vector<pair<double, pi>> lines;
	lines.push_back({ 0, { 0, 0 } });
	for (int i = 1; i <= m; i++) {
		auto it = prev(upper_bound(all(lines), make_pair((double)a[i], (pi)make_pair(1e18, 1e18))));
		ldp[i] = a[i] * (i + 1) - it->second.first * a[i] - it->second.second;

		pi cur = { i, -ldp[i] };
		while (lines.size() >= 2 && intersect((prev(prev(lines.end()))->second), lines.back().second) >= intersect(lines.back().second, cur)) {
			lines.pop_back();
		}
		lines.push_back({ intersect(lines.back().second, cur), cur });
	}

	vector<int> b(1);
	for (int i = 1; i <= m; i++) b.push_back(n + 1 - a[i]);
	b.push_back(0);
	reverse(all(b));
	b.pop_back();
	a = b;
	lines.clear();
	rdp[0] = 0;
	lines.push_back({ 0, { 0, 0 } });
	for (int i = 1; i <= m; i++) {
		auto it = prev(upper_bound(all(lines), make_pair((double)a[i], (pi)make_pair(1e18, 1e18))));
		rdp[i] = a[i] * (i + 1) - it->second.first * a[i] - it->second.second;

		pi cur = { i, -rdp[i] };
		while (lines.size() >= 2 && intersect((prev(prev(lines.end()))->second), lines.back().second) >= intersect(lines.back().second, cur)) {
			lines.pop_back();
		}
		lines.push_back({ intersect(lines.back().second, cur), cur });
	}
	vector<int> realrdp(m + 2);
	for (int i = 1; i <= m; i++) realrdp[i] = rdp[m + 1 - i];
	int ans = 1e18;
	for (int i = 0; i <= m; i++) ans = min(ans, ldp[i] + realrdp[i + 1]);
	cout << ans;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}