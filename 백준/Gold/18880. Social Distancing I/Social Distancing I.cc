#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') a.push_back(i + 1);
	}
	if (a.empty()) {
		cout << n - 1 << '\n';
		return;
	}
	int mn = 1e18;
	for (int i = 1; i < a.size(); i++) {
		mn = min(mn, a[i] - a[i - 1]);
	}
	vector<int> one(a.size() + 1), two(a.size() + 1);
	one[0] = a[0] - 1;
	two[0] = (a[0] - 1) / 2;
	one[a.size()] = n - a.back();
	two[a.size()] = (n - a.back()) / 2;
	for (int i = 1; i < a.size(); i++) {
		one[i] = (a[i] - a[i - 1]) / 2;
		two[i] = (a[i] - a[i - 1]) / 3;
	}
	sort(all(one), greater<int>());
	sort(all(two), greater<int>());
	cout << min(mn, max(min(one[0], one[1]), two[0])) << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}