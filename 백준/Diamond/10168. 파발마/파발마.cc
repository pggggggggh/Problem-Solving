#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

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
	ldp[0] = rdp[m + 1] = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < i; j++) {
			ldp[i] = min(ldp[i], ldp[j] + a[i] * (i - j + 1));
		}
	}
	for (int i = m; i >= 1; i--) {
		for (int j = i + 1; j <= m + 1; j++) {
			rdp[i] = min(rdp[i], rdp[j] + (n - a[i] + 1) * (j - i + 1));
		}
	}
	int ans = 1e18;
	for (int i = 0; i <= m; i++) ans = min(ans, ldp[i] + rdp[i + 1]);
	cout << ans;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}