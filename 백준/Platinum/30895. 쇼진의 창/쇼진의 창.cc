#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int a, b, k;
	cin >> a >> b >> k;
	int ab = a + b;
	int tc = 1e7;
	int mni = k;

	// for (int i = 1; i <= 5 * k; i++) {
	// 	cout << i << ':' << (double)((i + a - 1) / a) / ((i + a + b - 1) / (a + b)) << '\n';
	// }

	for (int i = (k + a + b - 1) / (a + b) * (a + b) + 1; tc; tc--, i += ab) {
		if (((i + a - 1) / a) * ((mni + a + b - 1) / (a + b)) < ((mni + a - 1) / a) * ((i + a + b - 1) / (a + b)))
			mni = i;
	}
	cout << mni;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}