#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	string s;
	int q;
	cin >> s >> q;
	bitset<100005> bs[26];
	for (int i = 0; i < s.size(); i++) {
		bs[s[i] - 'a'][i] = 1;
	}
	while (q--) {
		string x;
		cin >> x;
		char a, c;
		int b;
		a = x[0], c = x.back();
		b = stoi(x.substr(1, x.size() - 2));
		cout << ((bs[a - 'a'] & (bs[c - 'a'] >> (b + 1))).count()) << '\n';
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}