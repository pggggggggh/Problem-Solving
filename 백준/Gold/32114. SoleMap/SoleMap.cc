#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

inline int sqr(int x)
{
	return x * x;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	n--;
	vector<int> a(n + 1), imos(n + 2);
	for (int i = 1; i <= n; i++) cin >> a[i];
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		imos[x] += z, imos[y] -= z;
	}
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		cur += imos[i];
		cout << sqr(cur / a[i] + 1) * (cur % a[i]) + sqr(cur / a[i]) * (a[i] - cur % a[i]) << '\n';
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}