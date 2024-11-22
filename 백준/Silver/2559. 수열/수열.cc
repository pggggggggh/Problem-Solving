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
	int sum = 0, r = 1; // [l,r)
	int res = -1e18;
	for (int l = 1; l <= n; l++) {
		while (r <= n && r - l < k) sum += a[r++];
		if (r - l == k) res = max(res, sum);
		sum -= a[l];
	}
	cout << res;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}