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

	vector<int> sa(n), pos(n);
	for (int i = 0; i < n; i++) {
		sa[i] = i;
		pos[i] = s[i];
	}
	int d;
	auto cmp = [&](int i, int j) {
		if (pos[i] != pos[j]) return pos[i] < pos[j];
		i += d, j += d;
		return (i < n && j < n) ? (pos[i] < pos[j]) : (i > j);
	};
	for (d = 1;; d *= 2) {
		sort(all(sa), cmp);
		vector<int> tmp = { 0 };
		for (int i = 0; i < n - 1; i++) tmp.push_back(tmp.back() + cmp(sa[i], sa[i + 1]));
		for (int i = 0; i < n; i++) pos[sa[i]] = tmp[i];
		if (tmp.back() == n - 1) break;
	}
	for (int i = 0; i < n; i++) cout << sa[i] + 1 << ' ';
	cout << '\n';

	vector<int> lcp(n);
	for (int i = 0, k = 0; i < n; i++, k = max(k - 1, 0LL)) {
		if (pos[i] == n - 1) continue;
		while (s[i + k] == s[sa[pos[i] + 1] + k]) k++;
		lcp[pos[i]] = k;
	}
	cout << "x ";
	for (int i = 0; i < n - 1; i++) cout << lcp[i] << ' ';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}