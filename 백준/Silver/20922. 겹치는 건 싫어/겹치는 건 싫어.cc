#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

int vis[100005];

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	int r = 0;
	int res = 0;
	for (int l = 1; l <= n; l++) {
		if (l > r) {
			r = l;
			vis[a[l]]++;
		}
		while (r + 1 <= n && vis[a[r + 1]] < k) {
			r++;
			vis[a[r]]++;
		}
		res = max(res, r - l + 1);
		vis[a[l]]--;
	}
	cout << res;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}