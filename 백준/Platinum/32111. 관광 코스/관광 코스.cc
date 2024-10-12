#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	string s;
	cin >> n >> s;
	if (s == string(n, 'X')) {
		cout << "YES\n"
		     << string(n, '-');
		return;
	}
	int shift = s.find('O');
	s = s.substr(shift, n - shift) + s.substr(0, shift);
	string res;
	int consec = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'O') {
			if (consec != 0 && consec % 2 == 0) {
				cout << "NO\n";
				return;
			}
			if (consec) res += string(consec / 2, '+') + string(consec / 2 + 1, '-');
			consec = 0;
			res += '+';
		} else consec++;
	}
	if (consec != 0 && consec % 2 == 0) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	if (consec) res += string(consec / 2, '+') + string(consec / 2 + 1, '-');
	for (int i = 0; i < n; i++) cout << res[(i - shift + n) % n];
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}