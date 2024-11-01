#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	set<int> s;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		if (s.count(x) || s.count(y) || s.count(z)) {
			cout << 1;
			return;
		}
		s.insert(x);
		s.insert(y);
		s.insert(z);
	}
	cout << 0;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}