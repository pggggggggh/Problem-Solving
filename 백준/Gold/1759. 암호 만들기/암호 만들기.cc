#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<char> a(m);
	for (int i = 0; i < m; i++) cin >> a[i];
	sort(all(a));
	vector<string> res;
	string s;
	function<void(int, int, int)> recur = [&](int cur, int last, int vow) {
		if (cur == n) {
			if (vow > 0 && n - vow >= 2) res.push_back(s);
			return;
		}
		for (int i = last + 1; i < m; i++) {
			s += a[i];
			int cur_vow = 0;
			if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') cur_vow = 1;
			recur(cur + 1, i, vow + cur_vow);
			s.pop_back();
		}
	};
	recur(0, -1, 0);
	sort(all(res));
	for (auto& s : res) cout << s << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}