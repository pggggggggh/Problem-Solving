#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<int> ans(n + 1);
	ans[1] = ans[n] = 1;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n == 1) {
		cout << "YES\n";
		return;
	}
	for (int i = 3; i <= n; i++) {
		if (a[i] - a[i - 1] < 2 * (a[i - 1] - a[i - 2])) {
			ans[1] = 0;
			break;
		}
	}
	for (int i = n - 2; i >= 1; i--) {
		if (a[i + 1] - a[i] < 2 * (a[i + 2] - a[i + 1])) {
			ans[n] = 0;
			break;
		}
	}
	vector<int> b(n + 1);
	b[0] = b[n] = -1e18;
	int s = -1;
	for (int i = 1; i <= n - 1; i++) {
		b[i] = a[i + 1] - a[i];
		if (s == -1 || b[i] < b[s]) {
			s = i;
		}
	}
	int e = s;
	int reals = s;
	int cur = b[s];
	int firstmove = 0;
	while (1) {
		// cout << s << ' ' << e << '\n';
		if (s == 1 && e == n - 1) {
			if (firstmove == -1) ans[reals] = 1;
			else ans[reals + 1] = 1;
			break;
		}
		if (b[s - 1] >= cur && b[e + 1] >= cur) {
			if (b[s - 1] < b[e + 1]) {
				if (firstmove == 0) firstmove = -1;
				s--;
				cur += b[s];
			} else {
				if (firstmove == 0) firstmove = 1;
				e++;
				cur += b[e];
			}
		} else if (b[s - 1] >= cur) {
			if (firstmove == 0) firstmove = -1;
			s--;
			cur += b[s];
		} else if (b[e + 1] >= cur) {
			if (firstmove == 0) firstmove = 1;
			e++;
			cur += b[e];
		} else {
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (ans[i]) cout << "YES\n";
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