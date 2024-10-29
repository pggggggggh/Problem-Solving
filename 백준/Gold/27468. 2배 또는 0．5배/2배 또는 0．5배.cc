#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	vector<int> vis(n + 1);
	vis[0] = 1;
	int cur = 1;
	if (n % 2 == 0 || n % 4 == 3) cur = 2;
	vis[cur] = 1;
	cout << "YES\n";
	cout << cur << ' ';
	while (cur < n || !vis[n - 1]) {
		if (!vis[cur - 1]) {
			cur--;
			vis[cur] = 1;
			cout << cur << ' ';
			if (cur + 2 > n) break;
			cur += 2;
			vis[cur] = 1;
			cout << cur << ' ';
		} else {
			cur++;
			vis[cur] = 1;
			cout << cur << ' ';
			if (cur == n && vis[n - 1]) break;
			cur += 2;
			vis[cur] = 1;
			cout << cur << ' ';
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}