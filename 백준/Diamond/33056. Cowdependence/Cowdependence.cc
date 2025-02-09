#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

int go(vector<int>& v, int x)
{
	auto it = v.begin();
	int res = 1;
	while (1) {
		it = upper_bound(all(v), *it + x);
		if (it != v.end()) res++;
		else break;
	}
	return res;
}

void solve()
{
	int n;
	cin >> n;
	vector<int> ar(n + 1);
	vector<vector<int>> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> ar[i];
		a[ar[i]].push_back(i);
	}
	int sq = sqrt(n);
	vector<int> event(n + 1);
	for (int i = 1; i <= n; i++) {
		if (a[i].size() >= sq) {
			int prev = 0;
			for (int x = 1; x <= n; x++) {
				int tmp = go(a[i], x);
				event[x] += tmp - prev;
				prev = tmp;
			}
		} else if ((int)a[i].size() > 0) {
			vector<int> st;
			st.push_back(1);
			for (int j = 0; j < a[i].size(); j++) {
				for (int k = j + 1; k < a[i].size(); k++) {
					st.push_back(a[i][k] - a[i][j]);
				}
			}
			sort(all(st));
			st.erase(unique(all(st)), st.end());
			int prev = 0;
			for (auto& x : st) {
				int tmp = go(a[i], x);
				event[x] += tmp - prev;
				prev = tmp;
			}
		}
	}

	int ans = 0;
	for (int x = 1; x <= n; x++) {
		ans += event[x];
		cout << ans << '\n';
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}