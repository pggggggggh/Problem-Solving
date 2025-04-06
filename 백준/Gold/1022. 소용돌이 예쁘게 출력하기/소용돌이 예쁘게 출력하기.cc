#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, -1, 0, 1 };
signed a[10005][50];

void solve()
{
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int ptr = 1;
	int x = 0, y = 0, dir = 3;
	for (int w = 0; w <= 5000; w++) {
		while (1) {
			if (y >= y1 && y <= y2) a[x + 5000][y - y1] = ptr;
			ptr++;
			if (abs(x + dx[dir]) > w || abs(y + dy[dir]) > w) {
				if (dir == 3) {
					y++;
					dir = 0;
					break;
				} else dir++;
			}
			x += dx[dir], y += dy[dir];
		}
	}
	int max_l = 0;
	for (int i = x1; i <= x2; i++) {
		for (int j = 0; j <= y2 - y1; j++) {
			max_l = max(max_l, (int)to_string(a[i + 5000][j]).size());
		}
	}
	for (int i = x1; i <= x2; i++) {
		for (int j = 0; j <= y2 - y1; j++) {
			int l = (int)to_string(a[i + 5000][j]).size();
			for (int k = 0; k < max_l - l; k++) cout << ' ';
			cout << a[i + 5000][j] << ' ';
		}
		cout << '\n';
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}