#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, k;
	cin >> n >> k;
	string s, t;
	cin >> s >> t;
	int ans = 0;
	set<pi> st;
	for (int i = 0; i < n; i++) {
		int d = (s[i] == '1') - (t[i] == '1'); // 1이면 1 0

		while (!st.empty() && st.begin()->first < i) {
			ans += abs(st.begin()->second);
			pi tmp = { st.begin()->first + k, st.begin()->second };
			st.erase(st.begin());
			st.insert(tmp);
		}
		if (!st.empty() && st.begin()->second * d < 0) {
			pi tmp = { st.begin()->first, st.begin()->second + d };
			st.erase(st.begin());
			if (tmp.second != 0) st.insert(tmp);
		} else if (d != 0) {
			int sex = 0;
			if (!st.empty() && st.begin()->first == i) {
				sex = st.begin()->second;
				st.erase(st.begin());
			}
			st.insert({ i, sex + d });
		}
	}
	cout << ans;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}