#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int cnt = 0;
	while (1) {
		int x;
		cin >> x;
		if (x == -1) return;
		if (cnt % 2) {
			if (rand() % 2) cout << "UP" << endl;
			else cout << "LEFT" << endl;
		} else {
			if (rand() % 2) cout << "DOWN" << endl;
			else cout << "RIGHT" << endl;
		}
		cnt++;
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}