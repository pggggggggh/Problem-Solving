#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

struct strongly_connected {
	int n;
	vector<vector<int>> adj;
	vector<vector<int>> scc;

	strongly_connected(int n) {
		this->n = n;
		adj.resize(n);
	}

	void add_edge(int from, int to) { adj[from].push_back(to); }

	vector<int> get_scc() {
		vector<int> dfn(n, -1);
		vector<int> sn(n, -1);
		int cnt = 0, scnt = 0;
		stack<int> stk;
		function<int(int)> dfs = [&](int v) {
			dfn[v] = ++cnt;
			stk.push(v);
			int res = dfn[v];
			for (auto &u : adj[v]) {
				if (dfn[u] == -1)
					res = min(res, dfs(u));
				else if (sn[u] == -1)
					res = min(res, dfn[u]);
			}
			if (res == dfn[v]) {
				while (1) {
					int t = stk.top();
					stk.pop();
					sn[t] = scnt;
					if (t == v) break;
				}
				scnt++;
			}
			return res;
		};
		for (int i = 0; i < n; i++) {
			if (dfn[i] == -1) dfs(i);
		}
		return sn;
	}
};

void solve() {
	string a, b;
	cin >> a >> b;
	int n = a.size();
	strongly_connected scc(100);
	vector<pi> edges;
	vector<int> mp(100, -1);  // 중복 제거
	set<int> st;              // B 갯수 체크
	for (int i = 0; i < n; i++) {
		if (mp[a[i] - 'A'] != -1) {
			if (mp[a[i] - 'A'] != b[i] - 'A') {
				cout << "-1\n";
				return;
			}
		}
		st.insert(b[i] - 'A');
		mp[a[i] - 'A'] = b[i] - 'A';
	}
	if (st.size() == 52 && a != b) {
		cout << "-1\n";
		return;
	}
	for (int i = 0; i < 100; i++) {
		if (mp[i] != -1) {
			scc.add_edge(i, mp[i]);
			edges.emplace_back(i, mp[i]);
		}
	}
	vector<int> sn = scc.get_scc();
	vector<int> indegree(100);
	int res = 0;
	for (auto &[u, v] : edges) {
		if (sn[u] != sn[v]) {
			res++;
			indegree[sn[v]]++;
		}
	}
	vector<int> cnt(100);
	for (int i = 0; i < 100; i++) {
		cnt[sn[i]]++;
	}
	for (int i = 0; i < 100; i++) {
		if (cnt[i] > 1) {
			if (indegree[i] >= 1) res--;
			res += cnt[i] + 1;
		}
	}
	cout << res << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) solve();
}