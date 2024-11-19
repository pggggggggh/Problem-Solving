#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int d, n;
	cin >> d >> n;
	vector<int> a(d + 1), price(d + 1);
	for (int i = 1; i <= d - 1; i++) {
		cin >> a[i];
	}
	price[d] = 1;
	for (int i = d - 1; i >= 1; i--) {
		price[i] = price[i + 1] * a[i];
	}
	vector<int> res;
	while (n--) {
		int cur = 0;
		for (int i = 1; i <= d; i++) {
			int x;
			cin >> x;
			cur += price[i] * x;
		}
		res.push_back(cur);
	}
	sort(all(res));
	cout << res.back() - res[0] << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Data Set " << i << ":\n";
		solve();
		cout << '\n';
	}
}