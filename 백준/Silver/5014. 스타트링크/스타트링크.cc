#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, s, e, u, d;
	cin >> n >> s >> e >> u >> d;
	queue<int> q;
	vector<int> dist(n + 1, 1e18), vis(n + 1);
	q.push(s);
	dist[s] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == e) break;
		if (vis[cur]) continue;
		vis[cur] = 1;

		if (cur - d > 0) {
			if (!vis[cur - d]) {
				dist[cur - d] = min(dist[cur - d], dist[cur] + 1);
				q.push(cur - d);
			}
		}
		if (cur + u <= n) {
			if (!vis[cur + u]) {
				dist[cur + u] = min(dist[cur + u], dist[cur] + 1);
				q.push(cur + u);
			}
		}
	}
	cout << (dist[e] == 1e18 ? "use the stairs" : to_string(dist[e]));
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}