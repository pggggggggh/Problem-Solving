#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

vector<int> adj[10005];
vector<int> id(10005), finished(10005);
int dfn;
vector<vector<int>> sccs;
vector<int> stk;

int go(int u)
{
	id[u] = ++dfn;
	stk.push_back(u);
	int top = id[u];
	for (auto& v : adj[u]) {
		if (id[v] == 0) top = min(top, go(v));
		else if (!finished[v]) top = min(top, id[v]);
	}
	if (top == id[u]) {
		vector<int> scc;
		while (1) {
			int tmp = stk.back();
			finished[tmp] = 1;
			scc.push_back(tmp);
			stk.pop_back();
			if (tmp == u) break;
		}
		sort(all(scc));
		sccs.push_back(scc);
	}
	return top;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
		if (!id[i]) go(i);
	sort(all(sccs));
	cout << sccs.size() << '\n';
	for (auto& scc : sccs) {
		for (auto& x : scc) cout << x << ' ';
		cout << "-1\n";
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}