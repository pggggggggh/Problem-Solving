#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve() {
	string s, t;
	cin >> s >> t;
	vector<char> a;
	for (auto &c : s) {
		int ptr = t.size() - 1;
		a.push_back(c);
		vector<char> tmp;
		while (!a.empty() && ptr >= 0 && a.back() == t[ptr--]) {
			tmp.push_back(a.back());
			a.pop_back();
		}
		if (tmp.size() != t.size()) {
			while (!tmp.empty()) {
				a.push_back(tmp.back());
				tmp.pop_back();
			}
		}
	}
	for (auto &c : a) cout << c;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}