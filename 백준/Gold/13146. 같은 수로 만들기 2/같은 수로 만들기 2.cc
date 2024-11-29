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
	cin >> a[1];
	int mx = a[1], res = 0;
	for (int i = 2; i <= n; i++) {
		cin >> a[i];
		if (a[i] > mx) {
			res += a[i] - mx;
			mx = a[i];
		} else if (a[i] < a[i - 1]) res += a[i - 1] - a[i];
	}
	cout << res;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}