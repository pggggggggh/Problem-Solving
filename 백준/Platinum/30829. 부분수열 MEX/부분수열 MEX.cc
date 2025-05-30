#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	string s;
	cin >> s;
	int n = s.size();
	s += "0123456789"; // n+10
	set<int> st;
	vector<int> dp(n + 15);
	vector<set<int>> pos(10);
	for (int i = 0; i < n + 10; i++) pos[s[i] - '0'].insert(i);
	dp[n] = 1;
	for (int i = n - 1; i >= 0; i--) {
		st.insert(s[i] - '0');
		if (st.size() == 10) {
			dp[i] = dp[i + 1] + 1;
			st.clear();
		} else dp[i] = dp[i + 1];
	}
	int cur = -1;
	while (1) {
		int nxt = 0, mn = 1e18;
		for (int i = 0; i < 10; i++) {
			if (cur == -1 && i == 0) continue;
			int sex = *pos[i].lower_bound(cur + 1);
			if (dp[sex + 1] < mn) {
				mn = dp[sex + 1];
				nxt = sex;
			}
		}
		cur = nxt;
		cout << s[cur];
		if (cur >= n) break;
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}