#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, q;
	cin >> n >> q;
	vector<set<int>> garo(q + 1), sero(q + 1);
	for (int i = 1; i <= n; i++) {
		garo[0].insert(i);
		sero[0].insert(i);
	}
	vector<int> garov(n + 1), serov(n + 1);
	int garomx = 0, seromx = 0;
	while (q--) {
		int x, y;
		cin >> x >> y;
		if (x == 1) {
			int idx = garov[y];
			garov[y]++;
			garo[idx].erase(y);
			garo[idx + 1].insert(y);
			if (idx + 1 > garomx) garomx = idx + 1;
		} else {
			int idx = serov[y];
			serov[y]++;
			sero[idx].erase(y);
			sero[idx + 1].insert(y);
			if (idx + 1 > seromx) seromx = idx + 1;
		}
		cout << garo[garomx].size() * sero[seromx].size() << '\n';
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}