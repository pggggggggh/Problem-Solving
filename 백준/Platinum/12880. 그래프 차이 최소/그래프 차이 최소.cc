#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v)    \
	sort(all(v)); \
	v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
struct SCC {
	int n, cnt, scc_id;
	vector<vector<int>> G, scc;
	vector<int> id, fin, S;
	SCC(int n_, vector<vector<int>> G_)
	    : id(n_ + 1), fin(n_ + 1), cnt(0), scc_id(0)
	{
		n = n_;
		G = G_;
	}
	int dfs(int v)
	{
		int top = id[v] = ++cnt;
		S.push_back(v);
		for (int nx : G[v]) {
			if (!id[nx]) top = min(top, dfs(nx));
			else if (!fin[nx]) top = min(top, id[nx]);
		}
		if (top == id[v]) {
			vector<int> tmp;
			while (S.size()) {
				int u = S.back();
				S.pop_back();
				fin[u] = 1;
				tmp.push_back(u);
				if (u == v) break;
			}
			scc.push_back(tmp);
			scc_id++;
		}
		return top;
	}
	void go()
	{
		for (int s = 1; s <= n; s++)
			if (!id[s]) dfs(s);
	}
};
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	vector<array<ll, 3>> edge;
	for (int s = 1; s <= n; s++) {
		for (int e = 1; e <= n; e++) {
			int k;
			cin >> k;
			if (s ^ e) edge.push_back({ k, s, e });
		}
	}
	int sz = edge.size();
	sort(all(edge));
	auto jud = [&](int len) {
		for (int s = 0, e = 0; s < sz; s++) {
			while (e < sz && edge[s][0] + len >= edge[e][0]) e++;
			vector<vector<int>> G(n + 1);
			for (int x = s; x < e; x++) {
				auto [w, u, v] = edge[x];
				G[u].push_back(v);
			}
			SCC scc(n, G);
			scc.go();
			if (scc.scc_id == 1) return 1;
		}
		return 0;
	};
	int l = -1, r = 202020;
	while (l + 1 < r) {
		int m = (l + r) >> 1;
		if (jud(m)) r = m;
		else l = m;
	}
	cout << r;
}