#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

vector<int> z_func(const string& s)
{
	// z[i] = length of longest matching prefix of s[0..] and s[i..]
	vector<int> z(s.size());
	z[0] = s.size();
	int l = 0, r = 0; // [l,r)
	for (int i = 1; i < s.size(); i++) {
		if (i < r) z[i] = min(r - i, z[i - l]);
		while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]]) {
			z[i]++;
		}
		if (i + z[i] > r) {
			l = i;
			r = i + z[i];
		}
	}
	return z;
}

void solve()
{
	int n;
	string s;
	cin >> n >> s;
	int msb = s.find_first_of('1');
	if (msb == -1) {
		cout << "0\n";
		return;
	}
	string s1 = s.substr(msb);
	int firstzero = s1.find_first_of('0');
	if (firstzero == -1) {
		if (msb == 0) cout << string(s1.size() - 1, '1') + '0' << '\n';
		else cout << string(s1.size(), '1') << '\n';
		return;
	}
	string tofind;
	for (int i = 0; i < (int)s1.size(); i++) {
		if (s1[i] == '0') tofind += '1';
		else tofind += '0';
	}
	tofind = tofind.substr(tofind.find_first_of('1'));
	string x = tofind + '#' + s1;
	vector<int> z = z_func(x);
	int mxz = -1, mxidx = -1;
	for (int i = tofind.size() + 1; i < tofind.size() + 1 + firstzero; i++) {
		if (z[i] > mxz) {
			mxz = z[i];
			mxidx = i - (int)tofind.size() - 1;
		}
	}
	string s2 = s1.substr(mxidx, s1.size() - firstzero);
	s2 = string(s1.size() - s2.size(), '0') + s2;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == s2[i]) cout << '0';
		else cout << '1';
	}
	cout << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) solve();
}