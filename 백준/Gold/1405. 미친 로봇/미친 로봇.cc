#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

int vis[31][31];
int n;
double p[4];
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };

double recur(int now, int x, int y, int d) // 이미 now칸 이동했을 떄
{
	if (now == n) {
		return 1;
	}
	vis[x][y] = 1;
	double ret = 0;
	for (int i = 0; i < 4; i++) {
		if (vis[x + dx[i]][y + dy[i]]) continue;
		ret += p[i] * recur(now + 1, x + dx[i], y + dy[i], i);
	}
	vis[x][y] = 0;
	return ret;
}

void solve()
{
	cin >> n;
	for (int i = 0; i < 4; i++) {
		cin >> p[i];
		p[i] /= 100;
	}
	cout << setprecision(12) << fixed << recur(0, 15, 15, 100);
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}