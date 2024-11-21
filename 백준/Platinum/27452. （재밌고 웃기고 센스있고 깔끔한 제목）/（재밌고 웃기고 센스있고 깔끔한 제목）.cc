#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

vector<int> a(105);

int recur(int n, int k) // (가 0
{
	if (n <= 2) {
		if (k <= 1) return 0;
		if (k == 2) return 1;
		return -1;
	}
	if (k <= 1) return 0;
	if (k == a[n]) return 1;
	if (k > a[n]) return -1;
	if (k <= 1 + a[n - 2]) return recur(n - 2, k - 1);
	return recur(n - 1, k - 1 - a[n - 2]);
}

void solve()
{
	int n, k;
	cin >> n >> k;
	int res;
	if (n > 87) {
		if (n % 2 == 0) {
			res = recur(86, k - (n - 86) / 2);
		} else {
			res = recur(87, k - (n - 87) / 2);
		}
	} else res = recur(n, k);
	if (res == -1) cout << 0 << '\n';
	else if (res == 0) cout << '(' << '\n';
	else cout << ')' << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	a[1] = 2, a[2] = 2;
	for (int i = 3; i <= 87; i++) a[i] = a[i - 2] + a[i - 1] + 2;
	int t;
	cin >> t;
	while (t--) solve();
}