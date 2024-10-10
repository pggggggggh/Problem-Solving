#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	vector<vector<int>> dp(n + 1, vector<int>(4, -1));
	function<int(int, int)> recur = [&](int u, int c) {
		int &ret = dp[u][c];
		if (ret != -1) return ret;
		if (c == 3) return ret = 1;
		if (u == n) return ret = 0;
		ret = 0;
		if (s[u] == "COW"[c]) ret += recur(u + 1, c + 1);
		ret += recur(u + 1, c);
		return ret;
	};
	cout << recur(0, 0);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}