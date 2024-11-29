#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a[i] = a[i] - x;
	}
	int res = 0;
	res += abs(a[1]);
	for (int i = 2; i <= n; i++) res += abs(a[i] - a[i - 1]);
	res += abs(a[n]);
	cout << res / 2;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}