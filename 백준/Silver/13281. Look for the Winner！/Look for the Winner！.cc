#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

int n;

void solve()
{
	vector<int> a(26, 0);
	int mx = 0;
	int ans = -1;
	for (int i = 1; i <= n; i++) {
		char x;
		cin >> x;
		a[x - 'A']++;
		mx = max(mx, a[x - 'A']);
		int mxi = -1;
		for (int j = 0; j < 26; j++) {
			if (mxi == -1 || a[j] > a[mxi]) {
				mxi = j;
			}
		}
		int mxj = -1;
		for (int j = 0; j < 26; j++) {
			if (j == mxi) continue;
			if (mxj == -1 || a[j] > a[mxj]) {
				mxj = j;
			}
		}
		if (a[mxi] - a[mxj] > n - i && ans == -1) {
			ans = i;
		}
	}
	int mxi = -1;
	for (int i = 0; i < 26; i++) {
		if (mxi == -1 || a[i] > a[mxi]) mxi = i;
	}
	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (a[i] == a[mxi]) cnt++;
	}
	if (cnt > 1) cout << "TIE\n";
	else cout << (char)(mxi + 'A') << ' ' << ans << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> n;
		if (n == 0) break;
		solve();
	}
}