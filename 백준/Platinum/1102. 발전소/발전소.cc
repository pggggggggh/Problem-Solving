#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

int adj[20][20];
int dp[70000];

void solve()
{
	int n, p;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> adj[i][j];
		}
	}
	string s;
	cin >> s;
	cin >> p;
	int state = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'Y') state |= (1LL << i);
	}

	memset(dp, -1, sizeof(dp));
	function<int(int)> recur = [&](int state) {
		int& ret = dp[state];
		if (ret != -1) return ret;
		vector<int> noalive, alive;
		for (int i = 0; i < n; i++) {
			if ((state >> i) & 1) {
				alive.push_back(i);
			} else noalive.push_back(i);
		}
		if (alive.size() >= p) return ret = 0;
		ret = 1e18;
		for (auto& x : noalive) {
			int cost = 1e18;
			for (auto& y : alive) {
				cost = min(cost, adj[y][x]);
			}
			ret = min(ret, recur(state | (1LL << x)) + cost);
		}
		return ret;
	};
	int ans = recur(state);
	cout << (ans == 1e18 ? -1 : ans);
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}