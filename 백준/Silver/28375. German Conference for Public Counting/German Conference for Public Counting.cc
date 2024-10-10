#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve() {
	int a;
	cin >> a;
	string s = to_string(a);
	int res = max(1LL, (int)s.size() - 1);  // 0
	for (int i = 1; i <= 9; i++) {
		int flag = 1;
		int cur = i;
		for (int j = 1; j <= s.size(); j++) {
			if (cur > a) {
				flag = 0;
				break;
			}
			cur = cur * 10 + i;
		}
		if (flag)
			res += s.size();
		else
			res += s.size() - 1;
	}
	cout << res;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}