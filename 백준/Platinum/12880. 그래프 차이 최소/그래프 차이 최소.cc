#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

int a[105][105];

struct strongly_connected {
	int n;
	vector<vector<int>> adj;

	strongly_connected(int n)
	    : n(n)
	{
		adj.resize(n + 1);
		id.resize(n + 1);
		finished.resize(n + 1);
	}

	void add_edge(int s, int e)
	{
		adj[s].push_back(e);
	}

	int dfn = 0;
	vector<int> id, finished;
	vector<int> stk;
	vector<vector<int>> sccs;

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
			while (stk.back() != u) {
				finished[stk.back()] = 1;
				scc.push_back(stk.back());
				stk.pop_back();
			}
			finished[stk.back()] = 1;
			scc.push_back(stk.back());
			stk.pop_back();
			sccs.push_back(scc);
		}

		return top;
	}

	int get_scc()
	{
		for (int i = 1; i <= n; i++) {
			if (!id[i]) go(i);
		}
		return sccs.size();
	}
};

void solve()
{
	int n;
	cin >> n;
	set<int> st;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			st.insert(a[i][j]);
		}
	}
	int res = 1e18;
	for (auto& s : st) {
		int lo = -1, hi = 1e9;
		while (lo + 1 < hi) {
			int mid = lo + hi >> 1;
			strongly_connected scc(n);
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (a[i][j] >= s && a[i][j] <= s + mid) scc.add_edge(i, j);
				}
			}
			if (scc.get_scc() == 1) {
				hi = mid;
			} else lo = mid;
		}
		res = min(res, hi);
	}
	cout << res << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}