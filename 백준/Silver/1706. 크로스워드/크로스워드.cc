#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector a(n + 1, vector<char>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	}
	set<string> st;
	for (int i = 1; i <= n; i++) {
		string cur = "";
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == '#') {
				if (cur.size() > 1) st.insert(cur);
				cur.clear();
			} else {
				cur += a[i][j];
			}
		}
		if (cur.size() > 1) st.insert(cur);
	}
	for (int i = 1; i <= m; i++) {
		string cur = "";
		for (int j = 1; j <= n; j++) {
			if (a[j][i] == '#') {
				if (cur.size() > 1) st.insert(cur);
				cur.clear();
			} else {
				cur += a[j][i];
			}
		}
		if (cur.size() > 1) st.insert(cur);
	}
	cout << *st.begin();
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}