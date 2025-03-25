#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	string s;
	cin >> n >> s;
	vector<int> sa(n), lcp(n), pos(n);
	for (int i = 0; i < n; i++) {
		sa[i] = i;
		pos[i] = s[i];
	}
	int d = 1;
	auto cmp = [&](int i, int j) {
		if (pos[i] != pos[j]) return pos[i] < pos[j];
		i += d, j += d;
		if (i >= n || j >= n) return i > j; // 더 짧은 게 앞으로
		return pos[i] < pos[j];
	};
	for (d = 1;; d *= 2) {
		sort(all(sa), cmp);
		vector<int> tmp = { 0 };
		for (int i = 1; i < n; i++) tmp.push_back(tmp.back() + cmp(sa[i - 1], sa[i]));
		for (int i = 0; i < n; i++) pos[sa[i]] = tmp[i];
		if (tmp[n - 1] == n - 1) break;
	}
	for (int i = 0, k = 0; i < n; i++, k = max(k - 1, 0LL)) {
		if (pos[i] == n - 1) continue;
		while (s[i + k] == s[sa[pos[i] + 1] + k]) k++;
		lcp[pos[i]] = k;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) ans = max(ans, lcp[i]);
	cout << ans;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}