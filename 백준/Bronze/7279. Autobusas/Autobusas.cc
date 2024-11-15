#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, m;
	cin >> n >> m;
	int mx = 0;
	int cur = 0;
	while (n--) {
		int x, y;
		cin >> x >> y;
		cur += x;
		cur -= y;
		mx = max(mx, cur);
	}
	cout << max(0LL, mx - m);
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}