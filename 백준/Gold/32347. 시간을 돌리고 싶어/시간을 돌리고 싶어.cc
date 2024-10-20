#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> a;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x) a.push_back(i);
	}
	int lo = 0, hi = n - 1;
	while (lo + 1 < hi) {
		int mid = lo + hi >> 1;
		int cur = n;
		int cnt = 0;
		while (cur > 1 && cnt <= k) {
			int tm = *lower_bound(all(a), cur);
			cur = tm - mid;
			cnt++;
		}
		if (cur <= 1 && cnt <= k) hi = mid;
		else lo = mid;
	}
	cout << hi;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}