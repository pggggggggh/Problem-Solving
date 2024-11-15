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
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		if (s == "mumble") continue;
		if (stoi(s) != i) {
			cout << "something is fishy";
			return;
		}
	}
	cout << "makes sense";
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}