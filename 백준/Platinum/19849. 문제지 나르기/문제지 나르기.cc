#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

int a[50005][12];

void solve()
{
	int n, q;
	cin >> n >> q;
	vector<int> mx(3000, -1e18), mn(3000, 1e18);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 11; j++) cin >> a[i][j];
	}
	for (int state = 0; state < (1LL << 11); state++) {
		for (int i = 0; i < n; i++) {
			int cur = 0;
			for (int j = 0; j < 11; j++) {
				if ((state >> j) & 1) cur += a[i][j];
				else cur -= a[i][j];
			}
			mx[state] = max(mx[state], cur);
			mn[state] = min(mn[state], cur);
		}
	}
	vector<int> b(11);
	while (q--) {
		for (int i = 0; i < 11; i++) cin >> b[i];
		int res = 0;
		for (int state = 0; state < (1LL << 11); state++) {
			int cur = 0;
			for (int i = 0; i < 11; i++) {
				if ((state >> i) & 1) cur += b[i];
				else cur -= b[i];
			}
			res = max(res, mx[state] - cur);
			res = max(res, cur - mn[state]);
		}
		cout << res << '\n';
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}