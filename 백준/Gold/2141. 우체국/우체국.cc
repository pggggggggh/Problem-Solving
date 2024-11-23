#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
#define X first
#define Y second
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	vector<pi> a(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i].X >> a[i].Y;
		sum += a[i].Y;
	}
	sort(all(a));
	int cur = 0, ptr = 0;
	while (cur < (sum + 1) / 2) cur += a[ptr++].Y;
	cout << a[ptr - 1].X;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}