#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	for (int i = 0; i < 8; i++) {
		int x;
		cin >> x;
		if (x != 0 && x != 1) {
			cout << "F";
			return;
		}
	}
	cout << "S";
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}