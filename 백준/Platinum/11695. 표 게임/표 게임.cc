#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, m;
	int res = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int cur = 0;
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			cur += x;
		}
		res ^= cur;
	}
	if (res)
		cout << "august14";
	else
		cout << "ainta";
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}