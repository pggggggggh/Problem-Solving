#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1);
	set<int> idx;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i]) idx.insert(i);
	}
	int pos = 1;
	while (q--) {
		int x, y;
		cin >> x;
		if (x == 1) {
			cin >> y;
			if (a[y] == 1) {
				a[y] = 0;
				idx.erase(y);
			} else {
				a[y] = 1;
				idx.insert(y);
			}
		} else if (x == 2) {
			cin >> y;
			pos = (pos + y) % n;
			if (pos == 0) pos = n;
		} else {
			if (idx.empty()) cout << -1 << '\n';
			else {
				if (idx.lower_bound(pos) == idx.end()) cout << *idx.begin() + n - pos << '\n';
				else cout << *idx.lower_bound(pos) - pos << '\n';
			}
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}