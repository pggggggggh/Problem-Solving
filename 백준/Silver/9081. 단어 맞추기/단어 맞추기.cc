#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	string s;
	cin >> s;
	int n = s.size();
	for (int i = n - 2; i >= 0; i--) {
		int idx = -1;
		for (int j = i + 1; j < n; j++) {
			if (s[j] > s[i]) {
				if (idx == -1 || s[j] < s[idx]) idx = j;
			}
		}
		if (idx == -1) continue;
		swap(s[idx], s[i]);
		sort(s.begin() + i + 1, s.end());
		break;
	}
	cout << s << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) solve();
}