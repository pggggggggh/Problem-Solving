#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	int sq = sqrt(n);
	vector<int> a(n + 1), bkt(sq + 1, 1e18);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		bkt[i / sq] = min(bkt[i / sq], a[i]);
	}
	int q;
	cin >> q;
	while (q--) {
		int x, y, z;
		cin >> x >> y >> z;
		if (x == 1) {
			a[y] = z;
			bkt[y / sq] = 1e18;
			for (int i = (y / sq) * sq; i < (y / sq + 1) * sq; i++) bkt[y / sq] = min(bkt[y / sq], a[i]);
		} else {
			int res = 1e18, l = y, r = z;
			while ((l % sq) && l <= r) res = min(res, a[l++]);
			while (((r + 1) % sq) && l <= r) res = min(res, a[r--]);
			while (l <= r) {
				res = min(res, bkt[l / sq]);
				l += sq;
			}
			cout << res << '\n';
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}