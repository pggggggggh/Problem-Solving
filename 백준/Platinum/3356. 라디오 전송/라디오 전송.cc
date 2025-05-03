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
	string a;
	cin >> a;
	vector<int> fail(n);
	for (int i = 1, j = 0; i < n; i++) {
		while (j > 0 && a[i] != a[j]) j = fail[j - 1];
		if (a[i] == a[j]) fail[i] = ++j;
	}
	cout << n - fail[n - 1] << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}