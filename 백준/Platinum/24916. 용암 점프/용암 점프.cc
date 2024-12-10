#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 2);
	a[0] = 1e18;
	a[n + 1] = -1e18;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n == 1) {
		cout << "YES\n";
		return;
	}
	function<int(int)> go = [&](int s) {
		int e = s;
		int se = 0; // 0이면 s, 1이면 e
		int cha = 0;
		while (1) {
			if (s == 1 && e == n) return 1;
			if (se) {
				if (a[e] - a[s - 1] >= 2 * cha && a[e + 1] - a[e] >= 2 * cha) {
					if (rand() % 2) {
						cha = a[e] - a[s - 1];
						s--;
						se = 0;
					} else {
						cha = a[e + 1] - a[e];
						e++;
						se = 1;
					}
				} else if (a[e] - a[s - 1] >= 2 * cha) {
					cha = a[e] - a[s - 1];
					s--;
					se = 0;
				} else if (a[e + 1] - a[e] >= 2 * cha) {
					cha = a[e + 1] - a[e];
					e++;
					se = 1;
				} else return 0;
			} else {
				if (a[s] - a[s - 1] >= 2 * cha && a[e + 1] - a[s] >= 2 * cha) {
					if (rand() % 2) {
						cha = a[s] - a[s - 1];
						s--;
						se = 0;
					} else {
						cha = a[e + 1] - a[s];
						e++;
						se = 1;
					}
				} else if (a[s] - a[s - 1] >= 2 * cha) {
					cha = a[s] - a[s - 1];
					s--;
					se = 0;
				} else if (a[e + 1] - a[s] >= 2 * cha) {
					cha = a[e + 1] - a[s];
					e++;
					se = 1;
				} else return 0;
			}
		}
	};
	for (int i = 1; i <= n; i++) {
		int flag = 0;
		for (int tc = 0; tc < 2000; tc++) {
			if (go(i)) {
				flag = 1;
				break;
			}
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) solve();
}