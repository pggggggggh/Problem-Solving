#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> ind(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		ind[y]++;
	}
	cout << "1\n";
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {
			cout << i;
			return;
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}