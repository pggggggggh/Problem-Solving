#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	vector<int> cnt(300005);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	int lo = 0, hi = 300005;
	while (lo + 1 < hi) {
		int mid = lo + hi >> 1;
		int need = 1, taken = 0;
		for (int i = mid - 1; i >= 2; i--) {
			if (cnt[i] >= need) taken += need;
			else {
				taken += cnt[i];
				need += need - cnt[i];
				if (need > n) break;
			}
		}
		if (2 * need <= n - taken) lo = mid;
		else hi = mid;
	}
	cout << lo;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}