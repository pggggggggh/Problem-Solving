#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1), needed(n + 1), heights(n + 1);
	vector<int> naive(n + 1);
	int sum = 0;
	int stair = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		naive[i] = a[i];
		stair = max(stair - 1, a[i]);
		sum += a[i];
		needed[i] = (stair + stair + i - 1) * i / 2 - sum;
		heights[i] = stair + i - 1;
		// cout << needed[i] << ' ' << heights[i] << '\n';
	}
	int cur = 0;
	while (q--) {
		int x, y;
		cin >> x;
		if (x == 1) {
			cin >> y;
			cur += y;
			while (y--) {
				int idx = 1;
				while (idx < n && naive[idx] > naive[idx + 1]) idx++;
				naive[idx]++;
			}
		} else {
			int idx = prev(upper_bound(all(needed), cur)) - needed.begin();
			int orig_height = heights[idx];
			if (idx != n && heights[idx] == heights[idx + 1])
				cout << orig_height << '\n';
			else
				cout << orig_height + (cur - needed[idx]) / idx << '\n';
			// for (int i = 1; i <= n; i++) cout << naive[i] << ' ';
			// cout << " : " << cur;
			// cout << '\n';
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