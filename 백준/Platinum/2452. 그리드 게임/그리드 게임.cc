// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
using namespace std;
using pi = pair<int, int>;

int n, m;
bool a[101][101];
int dist[101][101];

struct union_find {
	int n;
	vector<int> par, sz;

	union_find(int n)
	    : n(n)
	{
		par.resize(n);
		sz.resize(n);
		for (int i = 0; i < n; i++) {
			par[i] = i;
			sz[i] = 1;
		}
	}

	int find(int x)
	{
		if (par[x] == x) return x;
		return par[x] = find(par[x]);
	}

	void uni(int x, int y)
	{
		x = find(x);
		y = find(y);
		if (x == y) return;
		par[y] = x;
		sz[x] += sz[y];
	}
};
int vis[30000];

void solve()
{
	union_find uf(30000);
	deque<array<int, 2>> dq;
	register int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i < n && a[i][j] == a[i + 1][j]) uf.uni(i * m + j, (i + 1) * m + j);
			if (j < m && a[i][j] == a[i][j + 1]) uf.uni(i * m + j, i * m + j + 1);
		}
	}
	int ans = 100;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (vis[uf.find(i * m + j)]) continue;
			vis[uf.find(i * m + j)] = 1;
			memset(dist, 0x3f3f3f3f, sizeof(dist));
			int cur = 0;
			dq.clear();
			dq.push_back({ i, j });
			dist[i][j] = 0;
			while (!dq.empty()) {
				int x = dq.front()[0];
				int y = dq.front()[1];
				dq.pop_front();
				int d = dist[x][y];
				if (d > ans) break;
				cur = max(cur, (int)dist[x][y]);
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k], ny = y + dy[k];
					if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
					int nd = d + (a[x][y] != a[nx][ny]);
					if (nd < dist[nx][ny]) {
						dist[nx][ny] = nd;
						if (nd == d) dq.push_front({ nx, ny });
						else dq.push_back({ nx, ny });
					}
				}
			}
			ans = min(ans, cur);
		}
	}
	cout << ans;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}