#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

int a[10][10];
int xsum[10], ysum[10];
int xanssum[10], yanssum[10];

void solve()
{
	int x;
	cin >> x;
	int anssum = 0;
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			cin >> a[i][j];
			a[i][j] -= x;
			anssum += a[i][j];
			xsum[i] += a[i][j];
			ysum[j] += a[i][j];
		}
	}
	anssum /= 15;
	for (int i = 1; i <= 8; i++) {
		xanssum[i] = (xsum[i] - anssum) / 7;
		yanssum[i] = (ysum[i] - anssum) / 7;
	}
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			int cur = xanssum[i] + yanssum[j] - a[i][j];
			if (cur == 0) cout << ". ";
			else if (cur > 0) cout << "+ ";
			else cout << "- ";
		}
		cout << '\n';
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}