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
	if (n <= 100000 && n % 2024 == 0) cout << "Yes";
	else cout << "No";
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}