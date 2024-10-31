#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	vector a(n + 2, vector<int>(n + 2, -1));
	int x, y;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 9) {
				x = i, y = j;
				a[i][j] = 0;
			}
		}
	}
	int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
	int sz = 2, ate = 0;
	int res = 0;
	while (1) {
		vector vis(n + 2, vector<int>(n + 2));
		queue<array<int, 3>> q;
		set<pi> minfish;
		int mindist = 1e18;
		q.push({ x, y, 0 });
		while (!q.empty()) {
			auto [curx, cury, curdist] = q.front();
			q.pop();
			if (vis[curx][cury]) continue;
			vis[curx][cury] = 1;

			if (a[curx][cury] > 0 && a[curx][cury] < sz) {
				if (curdist < mindist) {
					mindist = curdist;
					minfish.clear();
					minfish.insert({ curx, cury });
				} else if (curdist == mindist) {
					minfish.insert({ curx, cury });
				}
			}

			for (int i = 0; i < 4; i++) {
				int nx = curx + dx[i], ny = cury + dy[i];
				if (!vis[nx][ny] && a[nx][ny] != -1 && a[nx][ny] <= sz) {
					q.push({ nx, ny, curdist + 1 });
				}
			}
		}
		if (mindist == 1e18) break;
		auto [nx, ny] = *minfish.begin();
		res += mindist;
		ate++;
		if (ate == sz) {
			ate = 0;
			sz++;
		}
		a[nx][ny] = 0;
		x = nx, y = ny;
	}
	cout << res;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}