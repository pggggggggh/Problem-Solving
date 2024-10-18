#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	vector<int> notprime(2 * 1e7 + 5);
	for (int i = 2; i <= 2 * 1e7; i++) {
		if (notprime[i]) continue;
		for (int j = i * 2; j <= 2 * 1e7; j += i) notprime[j] = 1;
	}
	int n;
	cin >> n;
	vector<int> hol, jak;
	int one = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 1) {
			if (one) continue;
			else one = 1;
		}
		if (x % 2) hol.push_back(x);
		else jak.push_back(x);
	}
	vector adj(hol.size(), vector<int>());
	for (int i = 0; i < hol.size(); i++) {
		for (int j = 0; j < jak.size(); j++) {
			if (!notprime[hol[i] + jak[j]]) adj[i].push_back(j);
		}
	}
	vector<int> vis(hol.size());
	vector<int> r(hol.size(), -1), l(jak.size(), -1);
	function<int(int)> dfs = [&](int u) {
		vis[u] = 1;
		for (auto& v : adj[u]) {
			if (l[v] == -1 || (!vis[l[v]] && dfs(l[v]))) {
				r[u] = v;
				l[v] = u;
				return 1;
			}
		}
		return 0;
	};
	for (int i = 0; i < hol.size(); i++) {
		if (r[i] == -1) {
			fill(all(vis), 0);
			dfs(i);
		}
	}
	int res = 0;
	for (int i = 0; i < hol.size(); i++) {
		if (r[i] != -1) res++;
	}
	cout << hol.size() + jak.size() - res;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}