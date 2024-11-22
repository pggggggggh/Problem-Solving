#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	int res = 1e18, sum = 0;
	int r = 1;
	for (int l = 1; l <= n; l++) {
		while (r <= n && sum < k) sum += a[r++];
		if (sum >= k) res = min(res, r - l);
		sum -= a[l];
	}
	cout << (res == 1e18 ? 0 : res);
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}