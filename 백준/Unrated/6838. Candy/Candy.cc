#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

const int MX = 1000;

void solve() {
	int n;
	cin >> n;
	vector<pi> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].second >> a[i].first;
	sort(all(a), greater<pi>());

	int lo = -1, hi = MX;
	while (lo + 1 < hi) {
		vector dp(n + 1, vector<int>(MX + 5, -1));
		int mid = lo + hi >> 1;
		function<int(int, int)> recur = [&](int now, int diff) {
			int &ret = dp[now][diff];
			if (ret != -1) return ret;
			if (now == n) return ret = (diff <= mid);

			ret = 0;
			for (int i = a[now].second; i >= 0; i -= 2) {
				int now_diff = a[now].first * i;
				if (diff + now_diff <= MX)
					ret = max(ret, recur(now + 1, diff + now_diff));
				if (abs(diff - now_diff) <= MX)
					ret = max(ret, recur(now + 1, abs(diff - now_diff)));
			}

			return ret;
		};
		if (recur(0, 0))
			hi = mid;
		else
			lo = mid;
	}
	cout << hi;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}