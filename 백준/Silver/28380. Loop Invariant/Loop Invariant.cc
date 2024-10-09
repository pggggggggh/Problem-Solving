#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

namespace kmp {
vector<int> failure_func(string s) {
	vector<int> fail(s.size());
	for (int i = 1, j = 0; i < s.size(); i++) {
		while (j > 0 && s[i] != s[j]) j = fail[j - 1];
		if (s[i] == s[j]) fail[i] = ++j;
	}
	return fail;
}
}  // namespace kmp

void solve() {
	string s;
	cin >> s;
	vector<int> fail = kmp::failure_func(s);

	int n = s.size();
	if (fail[n - 1] != 0 && n % (n - fail[n - 1]) == 0) {
		cout << "no";
		return;
	}

	int cur = 0;
	vector<int> idx;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(')
			cur++;
		else
			cur--;
		if (cur == 0) idx.push_back(i);
	}
	if (idx.size() == 1) {
		cout << "no";
		return;
	}
	for (int i = idx[0] + 1; i < n; i++) cout << s[i];
	for (int i = 0; i <= idx[0]; i++) cout << s[i];
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}