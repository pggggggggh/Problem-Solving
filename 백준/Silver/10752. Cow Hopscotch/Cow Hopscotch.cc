#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve() {
	int r, c;
	cin >> r >> c;
	vector a(r + 2, vector<char>(c + 2));
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++) cin >> a[i][j];
	vector dp(20, vector(20, vector<int>(5, -1)));
	function<int(int, int, int)> recur = [&](int x, int y, int cur) {
		int &ret = dp[x][y][cur];
		if (ret != -1) return ret;
		if (x == r && y == c) return ret = 1;
		ret = 0;
		for (int nx = x + 1; nx <= r; nx++) {
			for (int ny = y + 1; ny <= c; ny++) {
				if (a[nx][ny] == "BR"[1 - cur]) ret += recur(nx, ny, 1 - cur);
			}
		}
		return ret;
	};
	if (a[1][1] == 'B')
		cout << recur(1, 1, 0);
	else
		cout << recur(1, 1, 1);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}