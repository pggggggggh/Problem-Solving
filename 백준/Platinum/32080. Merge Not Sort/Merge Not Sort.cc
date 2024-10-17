#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	n *= 2;
	vector<int> a(n);
	vector<vector<int>> block;
	vector<int> cur;
	int curmax = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i == 0) curmax = a[i];
		else if (a[i] > curmax) {
			block.push_back(cur);
			curmax = a[i];
			cur.clear();
		}
		cur.push_back(a[i]);
	}
	block.push_back(cur);
	int m = block.size();
	vector dp(m, vector<int>(n + 5));
	// i번째까지 j를 만들 수 있는가
	dp[0][0] = dp[0][block[0].size()] = 1;
	for (int i = 1; i < m; i++) {
		for (int j = 0; j <= n / 2; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - (int)block[i].size() >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - (int)block[i].size()]);
		}
	}
	if (dp[m - 1][n / 2] == 0) {
		cout << -1;
		return;
	}
	int cur_sz = n / 2;
	vector<int> ar, br;
	for (int i = m - 1; i >= 1; i--) {
		if (cur_sz - (int)block[i].size() >= 0 && dp[i - 1][cur_sz - (int)block[i].size()]) {
			ar.push_back(i);
			cur_sz -= (int)block[i].size();
		} else br.push_back(i);
	}
	if (cur_sz > 0) ar.push_back(0);
	else br.push_back(0);
	reverse(all(ar));
	reverse(all(br));
	for (auto& a : ar)
		for (auto& x : block[a]) cout << x << ' ';
	cout << '\n';
	for (auto& b : br)
		for (auto& x : block[b]) cout << x << ' ';
	cout << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}