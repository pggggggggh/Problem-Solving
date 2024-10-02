#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve() {
	int n;
	cin >> n;
	int cur = 0, cur2 = 0;
	int res = 0;
	while (n--) {
		int a, b;
		cin >> a >> b;
		cur2 += b;
		res = max(res, cur2 - cur);
		cur += a;
	}
	cout << res;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}