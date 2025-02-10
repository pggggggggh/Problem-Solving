#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

const int MOD = 998244353;

signed hfact[30000005], jfact[30000005], fact[30000005];

void solve()
{
	hfact[1] = 1, jfact[2] = 2, fact[1] = 1, fact[2] = 2;
	for (int i = 3; i <= 30000000; i++) {
		if (i % 2) {
			hfact[i] = (hfact[i - 2] * i) % MOD;
			jfact[i] = jfact[i - 1];
		} else {
			jfact[i] = (jfact[i - 2] * i) % MOD;
			hfact[i] = hfact[i - 1];
		}
		fact[i] = (fact[i - 1] * i) % MOD;
	}

	int n;
	cin >> n;
	if (n == 1) {
		cout << 1;
		return;
	}
	if (n < 14) {
		cout << -1;
		return;
	}
	int ans = 29030400 / 3;
	int left = n - 12;
	for (int y = 5;; y += 2) {
		int x = (y * y) + 1 / 2;

		if (left <= 2 * (y + 1)) {
			if (left <= y + 1) {
				ans = ans * hfact[2 * left - 1] % MOD;
			} else {
				ans = ans * hfact[2 * (y + 1) - 1] % MOD;
				ans = ans * jfact[2 * (left - y - 1)] % MOD;
			}
			break;
		}
		ans = ans * fact[2 * (y + 1)] % MOD;
		left -= 2 * (y + 1);
	}
	cout << ans;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}