#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

int yaksuspum(int x)
{
	int ret = 0;
	for (int l = 1, r; l <= x; l = r + 1) {
		int k = x / l;
		r = x / k;
		ret += (r - l + 1) * k;
	}
	return ret;
}

void solve()
{
	int n;
	cin >> n;
	int ans = 0;
	for (int l = 1, r; l <= n; l = r + 1) {
		int k = n / l;
		r = n / k;
		// cout << l << ' ' << r << ' ' << k << '\n';
		ans += k * (yaksuspum(r) - yaksuspum(l - 1));
	}
	cout << ans;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}