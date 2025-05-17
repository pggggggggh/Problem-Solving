#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

const int MOD = 1e9 + 7;

int gop[20000005];

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> ind(n);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		ind[x] += z;
		ind[y] += z;
	}
	int ans = 1;
	for (int i = 0; i < n; i++) {
		if (ind[i] % 2) {
			cout << 0;
			return;
		}
		ans = ans * gop[ind[i] - 1] % MOD;
	}
	cout << ans;
}

signed main()
{
	gop[1] = 1;
	for (int i = 3; i <= 20000000; i += 2) {
		gop[i] = gop[i - 2] * i % MOD;
	}

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}