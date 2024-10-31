#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	int res = 0;
	for (int i = 60; i >= 0; i--) {
		if ((1LL << i) <= n) {
			n -= (1LL << i);
			n = (1LL << i) - n;
			res++;
		}
	}
	cout << (n ^ (res % 2)) << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
}