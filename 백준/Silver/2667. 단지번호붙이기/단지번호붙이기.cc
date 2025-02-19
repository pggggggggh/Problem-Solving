#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

char a[50][50];
bool vis[50][50];
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };

void solve()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == '1' && !vis[i][j]) {
				queue<pair<int, int>> q;
				q.push({ i, j });
				int cnt = 0;
				while (!q.empty()) {
					auto [x, y] = q.front();
					q.pop();
					if (vis[x][y]) continue;
					cnt++;
					vis[x][y] = 1;
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k], ny = y + dy[k];
						if (a[nx][ny] == '1' && !vis[nx][ny]) q.push({ nx, ny });
					}
				}
				ans.push_back(cnt);
			}
		}
	}
	sort(all(ans));
	cout << ans.size() << '\n';
	for (auto& x : ans) cout << x << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}