#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector a(n + 2, vector<int>(m + 2, 1));
	int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
	int x, y, d;
	cin >> x >> y >> d;
	x++, y++;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	}
	int res = 0; // 1:벽
	while (1) {
		if (a[x][y] == 0) res++;
		a[x][y] = 2;
		int flag = 0;
		for (int i = 0; i < 4; i++) {
			d = (d + 3) % 4;
			if (a[x + dx[d]][y + dy[d]] == 0) {
				flag = 1;
				x += dx[d], y += dy[d];
				break;
			}
		}
		if (!flag) {
			if (a[x - dx[d]][y - dy[d]] == 1) break;
			else x -= dx[d], y -= dy[d];
		}
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