#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(360000), b(360000);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[x] = 1;
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		b[x] = 1;
	}
	a.insert(a.end(), all(a));
	int m = b.size();
	n = a.size();
	vector<int> fail(m);
	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && b[i] != b[j]) j = fail[j - 1];
		if (b[i] == b[j]) fail[i] = ++j;
	}
	vector<int> match(n);
	for (int i = 0, j = 0; i < n; i++) {
		while (j > 0 && a[i] != b[j]) j = fail[j - 1];
		if (a[i] == b[j]) {
			match[i] = ++j;
			if (j == m) j = fail[j - 1];
		}
	}
	if (*max_element(all(match)) != m) cout << "im";
	cout << "possible";
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}