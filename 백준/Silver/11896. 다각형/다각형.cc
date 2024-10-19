#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int a, b;
	cin >> a >> b;
	a = max(a, 4LL);
	if (a % 2) a--;
	else a -= 2;
	if (b % 2) b--;
	cout << max(0LL, b * (b + 2) / 4 - a * (a + 2) / 4);
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}