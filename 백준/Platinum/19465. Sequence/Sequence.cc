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
	vector<int> a(n + 1), b(n + 1), l(n + 1), r(n + 1);
	multiset<int> ams, bms;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ams.insert(a[i]);
		l[i] = r[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		bms.insert(b[i]);
	}
	while (m--) {
		int x, y;
		cin >> x >> y;
		for (int i = 1; i <= n; i++) {
			if (r[i] < x || y < l[i]) continue;
			l[i] = min(l[i], x);
			r[i] = max(r[i], y);
		}
	}
	if (ams != bms) {
		cout << "No\n";
		return;
	}
	vector<int> able(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = l[i]; j <= r[i]; j++) {
			if (a[i] == b[j] && !able[j]) {
				able[j] = 1;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!able[i]) {
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}