#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

int dp[65][(1 << 20) + 5];

void solve() {
	int t, n;
	cin >> t >> n;
	dp[0][0] = 1;
	int cur = 0;
	for (int i = 0; i < 3 * n; i++) {
		// i+1 consecutive light
		cur ^= (1 << (i % n));
		for (int j = 0; j < (1 << n); j++) {
			if (!dp[i][j]) continue;
			for (int k = 0; k < n; k++) {
				dp[i + 1][j ^ cur] = 1;
				cur <<= 1;
				if (cur & (1 << n)) cur ^= ((1 << n) + 1);
			}
		}
	}
	while (t--) {
		string sa, sb;
		int l = 0, sw = 0;
		cin >> sa >> sb;
		for (int i = 0; i < n; i++) l |= ((sa[i] - '0') << i);
		for (int i = 0; i < n; i++) sw |= ((sb[i] - '0') << i);
		int sw2 = 0;  // switch's influence on time i
		for (int i = 0; i <= 3 * n; i++) {
			if (dp[i][l ^ sw2]) {
				cout << i << '\n';
				break;
			}
			sw2 ^= sw;
			sw <<= 1;
			if (sw & (1 << n)) sw ^= ((1 << n) + 1);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}