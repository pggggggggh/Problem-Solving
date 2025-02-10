#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	s = ' ' + s;
	vector<int> a(n + 1);
	int curmx = 0;
	vector<int> b;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i > 1 && s[i] != s[i - 1]) {
			b.push_back(curmx);
			curmx = a[i];
		} else {
			curmx = max(curmx, a[i]);
		}
	}
	b.push_back(curmx);
	int m = b.size();
	vector<int> ans;
	for (int i = 1; i < m - 1; i++) ans.push_back(b[i]);
	sort(all(ans), greater<int>());
	int realans = 0;
	for (int i = 0; i < (m - 1) / 2; i++) realans += ans[i];
	cout << realans;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}