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
	vector<pi> a(n);
	int plusmn = 1e18, plusmx = -1e18, minusmn = 1e18, minusmx = -1e18;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		plusmn = min(plusmn, a[i].first + a[i].second);
		plusmx = max(plusmx, a[i].first + a[i].second);
		minusmn = min(minusmn, a[i].first - a[i].second);
		minusmx = max(minusmx, a[i].first - a[i].second);
	}
	cout << max(plusmx - plusmn, minusmx - minusmn);
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}