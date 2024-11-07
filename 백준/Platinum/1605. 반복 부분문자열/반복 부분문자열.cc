#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

const int m1 = 1e9 + 409;
const int m2 = 1e9 + 433;

void solve()
{
	int n;
	string s;
	cin >> n >> s;
	int lo = 0, hi = n + 1;
	map<int, int> mp;
	while (lo + 1 < hi) {
		mp.clear();
		int mid = lo + hi >> 1;
		int hsh1 = 0, hsh2 = 0;
		int pow1 = 1, pow2 = 1;
		for (int i = 0; i < mid; i++) {
			hsh1 = (hsh1 * 26 + s[i] - 'a') % m1;
			hsh2 = (hsh2 * 26 + s[i] - 'a') % m2;
			if (i != mid - 1) {
				pow1 = pow1 * 26 % m1;
				pow2 = pow2 * 26 % m2;
			}
		}
		mp[hsh1 * m2 + hsh2] = 1;
		int flag = 0;
		for (int i = mid; i < n; i++) {
			hsh1 = (hsh1 - (s[i - mid] - 'a') * pow1 % m1 + m1) % m1;
			hsh1 = (hsh1 * 26) % m1;
			hsh1 = (hsh1 + s[i] - 'a') % m1;
			hsh2 = (hsh2 - (s[i - mid] - 'a') * pow2 % m2 + m2) % m2;
			hsh2 = (hsh2 * 26) % m2;
			hsh2 = (hsh2 + s[i] - 'a') % m2;
			if (mp[hsh1 * m2 + hsh2]) {
				flag = 1;
				break;
			}
			mp[hsh1 * m2 + hsh2] = 1;
		}
		if (flag) lo = mid;
		else hi = mid;
	}
	cout << lo;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}