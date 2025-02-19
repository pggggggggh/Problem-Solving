#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

int a, b, c;
int dp[105][105][105];

int recur(int a, int b, int c)
{
	int& ret = dp[a + 50][b + 50][c + 50];
	if (ret != -1) return ret;

	if (a <= 0 || b <= 0 || c <= 0) return ret = 1;
	if (a > 20 || b > 20 || c > 20) return ret = recur(20, 20, 20);
	if (a < b && b < c) return ret = recur(a, b, c - 1) + recur(a, b - 1, c - 1) - recur(a, b - 1, c);
	return ret = recur(a - 1, b, c) + recur(a - 1, b - 1, c) + recur(a - 1, b, c - 1) - recur(a - 1, b - 1, c - 1);
}

void solve()
{
	cout << "w(" << a << ", " << b << ", " << c << ") = " << recur(a, b, c) << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	memset(dp, -1, sizeof(dp));

	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		solve();
	}
}