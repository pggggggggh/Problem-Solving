#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

constexpr int MOD1 = 1000001279;
constexpr int MOD2 = 1000001677;

void solve()
{
	string a, b;
	getline(cin, a);
	getline(cin, b);
	int n = a.size(), m = b.size();
	for (int i = 0; i < n; i++)
		if (a[i] == ' ') a[i] = 'A' + 26;
	for (int i = 0; i < m; i++)
		if (b[i] == ' ') b[i] = 'A' + 26;
	int pow1 = 1, pow2 = 1;
	int hsh1 = 0, hsh2 = 0;
	for (int i = 0; i < m; i++) {
		hsh1 = (hsh1 * 27 + b[i] - 'A') % MOD1;
		hsh2 = (hsh2 * 27 + b[i] - 'A') % MOD2;
		pow1 = (pow1 * 27) % MOD1;
		pow2 = (pow2 * 27) % MOD2;
	}
	int target = hsh1 * MOD2 + hsh2;
	hsh1 = hsh2 = 0;
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		hsh1 = (hsh1 * 27 + a[i] - 'A') % MOD1;
		hsh2 = (hsh2 * 27 + a[i] - 'A') % MOD2;
		if (i >= m) {
			hsh1 = (hsh1 - pow1 * (a[i - m] - 'A') % MOD1 + MOD1) % MOD1;
			hsh2 = (hsh2 - pow2 * (a[i - m] - 'A') % MOD2 + MOD2) % MOD2;
		}
		if (hsh1 * MOD2 + hsh2 == target) ans.push_back(i - m + 1);
	}
	cout << ans.size() << '\n';
	for (auto& x : ans) cout << x + 1 << ' ';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}