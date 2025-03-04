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
	vector<int> to(n + 1);
	for (int i = 1; i <= n; i++) cin >> to[i];
	vector<int> vis(n + 1), done(n + 1);
	vector<int> stk;
	vector<int> ans(n + 1);
	function<void(int)> dfs = [&](int u) {
		stk.push_back(u);
		vis[u] = 1;
		if (!vis[to[u]]) dfs(to[u]);
		else if (!done[to[u]]) {
			while (stk.back() != to[u]) {
				ans[stk.back()] = 1;
				stk.pop_back();
			}
			ans[to[u]] = 1;
		}
		done[u] = 1;
	};
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) dfs(i);
	}
	int realans = 0;
	for (int i = 1; i <= n; i++) realans += 1 - ans[i];
	cout << realans << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) solve();
}