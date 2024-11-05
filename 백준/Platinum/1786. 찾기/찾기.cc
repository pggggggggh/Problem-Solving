#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	string a, b;
	getline(cin, a);
	getline(cin, b);
	int n = a.size(), m = b.size();
	vector<int> fail(m);
	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && b[i] != b[j]) j = fail[j - 1];
		if (b[i] == b[j]) fail[i] = ++j;
	}
	vector<int> match(n);
	for (int i = 0, j = 0; i < n; i++) {
		while (j > 0 && a[i] != b[j]) j = fail[j - 1];
		if (a[i] == b[j]) match[i] = ++j;
	}
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (match[i] == m) ans.push_back(i);
	}
	cout << ans.size() << '\n';
	for (auto& x : ans) cout << x - m + 2 << ' ';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}