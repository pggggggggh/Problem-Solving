#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

int n, q;
vector<vector<int>> adj;
vector<int> depth, maxdepth; // dist from diameter
vector<int> subd; // diameter of subtree

vector<int> getdist(int s)
{
	vector<int> dist(n + 1, -1);
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto& v : adj[u]) {
			if (dist[v] != -1) continue;
			dist[v] = dist[u] + 1;
			q.push(v);
		}
	}
	return dist;
}

void getdepth(int u, int p)
{
	maxdepth[u] = depth[u];
	int mx = 0, mx2 = 0;
	for (auto& v : adj[u]) {
		if (v == p) continue;
		depth[v] = depth[u] + 1;
		getdepth(v, u);
		subd[u] = max(subd[u], subd[v]);
		maxdepth[u] = max(maxdepth[u], maxdepth[v]);
		if (maxdepth[v] >= mx) {
			mx2 = mx;
			mx = maxdepth[v];
		} else if (maxdepth[v] >= mx2) {
			mx2 = maxdepth[v];
		}
	}
	int withroot;
	if (mx2 == 0) withroot = mx - depth[u];
	else withroot = (mx + mx2) - 2 * depth[u];
	subd[u] = max(subd[u], withroot);
}

void solve()
{
	cin >> n >> q;
	adj.resize(n + 1);
	depth.resize(n + 1);
	maxdepth.resize(n + 1);
	subd.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vector<int> dist1 = getdist(1);
	int u = max_element(all1(dist1)) - dist1.begin();
	vector<int> distu = getdist(u);
	int v = max_element(all1(distu)) - distu.begin();

	vector<int> diameter;
	vector<int> didx(n + 1, -1);
	int cur = v;
	while (1) {
		diameter.push_back(cur);
		if (cur == u) break;
		for (auto& nxt : adj[cur]) {
			if (distu[nxt] < distu[cur]) {
				cur = nxt;
				break;
			}
		}
	}
	reverse(all(diameter));
	int d = diameter.size();
	for (int i = 0; i < d; i++) didx[diameter[i]] = i;
	vector<int> maxdistfromd(d);
	vector<int> prefixmax(d + 1), suffixmax(d + 1);
	for (int i = 0; i < d; i++) {
		for (auto& nxt : adj[diameter[i]]) {
			if (didx[nxt] != -1) continue;
			depth[nxt] = 1;
			getdepth(nxt, diameter[i]);
			maxdistfromd[i] = max(maxdistfromd[i], maxdepth[nxt]);
		}
	}
	// cout << u << ' ' << v << '\n';
	// for (int i = 0; i < d; i++) cout << maxdistfromd[i] << ' ';
	// for (int i = 1; i <= n; i++) cout << subd[i] << ' ';
	// cout << '\n';
	for (int i = 0; i < d; i++) {
		if (i) prefixmax[i] = prefixmax[i - 1];
		prefixmax[i] = max(prefixmax[i], i + maxdistfromd[i]);
	}
	for (int i = d - 1; i >= 0; i--) {
		suffixmax[i] = suffixmax[i + 1];
		suffixmax[i] = max(suffixmax[i], d - 1 - i + maxdistfromd[i]);
	}
	// for (int i = 0; i < d; i++) cout << prefixmax[i] << ' ' << suffixmax[i] << '\n';
	while (q--) {
		int x, y;
		cin >> x >> y;
		if (didx[x] != -1 && didx[y] != -1) {
			if (didx[x] > didx[y]) swap(x, y);
			// cout << d - 1 + maxdistfromd[didx[x]] + maxdistfromd[didx[y]] << '\n';
			cout << 1 + prefixmax[didx[x]] + suffixmax[didx[y]] << '\n';
		} else {
			if (depth[x] > depth[y]) swap(x, y);
			cout << d + subd[y] << '\n';
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}