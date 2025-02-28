#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, m;
	cin >> n >> m;
	map<string, int> mp;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		while (x--) {
			string s;
			cin >> s;
			mp[s]++;
		}
	}
	int res = 0;
	for (auto& [x, y] : mp) {
		if (y >= m) res++;
	}
	cout << res;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}