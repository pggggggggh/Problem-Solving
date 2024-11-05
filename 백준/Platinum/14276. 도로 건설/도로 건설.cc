#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

const int MOD = 1e9 + 7;

int n, m, k;
int dp[35][35][35][258];

int recur(int now, int left, int from, int state)
{
	int& ret = dp[now][left][from][state];
	if (ret != -1) return ret;
	if (now == n + 1) return ret = (left == 0);
	if (from == n + 1 || from == now + k + 1) {
		if (state & 1) return ret = 0;
		return ret = recur(now + 1, left, now + 2, state >> 1);
	}
	ret = 0;
	for (int i = 0; i <= left; i++) {
		ret = (ret + recur(now, left - i, from + 1, state ^ (((i & 1) << (from - now)) | (i & 1)))) % MOD;
	}
	return ret;
}

void solve()
{
	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> k;
	cout << recur(1, m, 2, 0);
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}