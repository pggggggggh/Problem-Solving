#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
#define PI acos(-1)
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	double res = 0;
	for (int i = 0; i < n; i++) {
		double a, d;
		cin >> a >> d;
		double t = d * sin(a / 180 * PI);
		res += t;
	}
	cout << setprecision(2) << fixed << res;
	;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}