#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1), cha;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i > 1) cha.push_back(a[i] - a[i - 1]);
	}
	sort(all(cha));
	int res = a[n] - a[1];
	for (int i = cha.size() - (k - 1); i < cha.size(); i++) res -= cha[i];
	cout << res;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}