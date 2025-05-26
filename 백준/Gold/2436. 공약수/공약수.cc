#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int a, b;
	cin >> a >> b;
	int gop = a * b;
	set<int> v;
	for (int i = 1; i * i <= gop; i++) {
		if (gop % i == 0) {
			v.insert(i);
			if (i * i != gop) v.insert(gop / i);
		}
	}
	int resx = 1e18, resy = 1e18;
	for (auto& x : v) {
		int y = gop / x;
		if (gcd(x, y) == a) {
			if (x + y < resx + resy) resx = x, resy = y;
		}
	}
	cout << resx << ' ' << resy;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}