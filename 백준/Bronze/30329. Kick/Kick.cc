#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	string s;
	cin >> s;
	int res = 0;
	for (int i = 0; i < s.size() - 3; i++) {
		if (s[i] == 'k' && s[i + 1] == 'i' && s[i + 2] == 'c' && s[i + 3] == 'k') res++;
	}
	cout << res;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}