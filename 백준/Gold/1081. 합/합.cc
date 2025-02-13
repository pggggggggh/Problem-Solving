#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int a, b;
	cin >> a >> b;
	int ans = 0, gop = 1;
	function<void(int)> go = [&](int x) {
		while (x) {
			ans += (x % 10) * gop;
			x /= 10;
		}
	};
	while (1) {
		while (a <= b && a % 10) {
			go(a);
			a++;
		}
		if (a > b) break;
		while (a <= b && b % 10 != 9) {
			go(b);
			b--;
		}
		if (a > b) break;
		ans += (b / 10 - a / 10 + 1) * 45 * gop;
		a /= 10;
		b /= 10;
		gop *= 10;
	}
	cout << ans;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}