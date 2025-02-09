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
	n += k;
	string a, b;
	cin >> a >> b;
	a = ' ' + a, b = ' ' + b;
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		if (a[i] == '1') v.push_back(i);
	}
	int ptr = 0, tot = 0;
	for (int i = 1; i <= n; i++) {
		if (b[i] == '1') {
			tot += abs(i - v[ptr++]);
		}
	}
	int asddsf = tot / 2;
	cout << asddsf * asddsf + (tot - asddsf) * (tot - asddsf);
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}