#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = n - 1; i >= 0; i--) {
		int chk = 1;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[i]) {
				chk = 0;
				break;
			}
		}
		if (chk == 0) {
			cout << i + 1;
			return;
		}
	}
	cout << 0;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}