#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	string a, b;
	cin >> a >> b;
	int n = a.size(), m = b.size();
	vector<int> fail(m);
	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && b[i] != b[j]) j = fail[j - 1];
		if (b[i] == b[j]) fail[i] = ++j;
	}
	vector<int> pastj(n);
	vector<char> ans;
	for (int i = 0, j = 0; i < n; i++) {
		ans.push_back(a[i]);
		while (j > 0 && a[i] != b[j]) j = fail[j - 1];
		if (a[i] == b[j]) {
			++j;
			if (j == m) {
				for (int k = 0; k < m; k++) ans.pop_back();
				j = pastj[ans.size()];
			}
		}
		pastj[ans.size()] = j;
	}
	for (auto& c : ans) cout << c;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}