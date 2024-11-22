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
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a.begin() + 1, a.end());
	int res = 0;
	for (int i = 1; i <= n; i++) {
		vector<int> b;
		for (int j = 1; j <= n; j++)
			if (i != j) b.push_back(a[j]);
		int r = n - 2;
		int flag = 0;
		for (int l = 0; l < r; l++) {
			while (l + 1 < r && b[l] + b[r] > a[i]) r--;
			if (b[l] + b[r] == a[i]) {
				flag = 1;
				break;
			}
		}
		res += flag;
	}
	cout << res;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}