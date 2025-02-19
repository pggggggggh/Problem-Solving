#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

int diff[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string ans[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

void solve()
{
	int x, y;
	cin >> x >> y;
	int cur = 0;
	for (int i = 1; i < x; i++) cur += diff[i];
	cur += y;
	cur--;
	cout << ans[cur % 7];
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}