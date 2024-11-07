#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 3), imos1(n + 3), imos2(n + 3);
	vector<int> imos_lazy(n + 3);
	while (k--) {
		int s, e;
		char x;
		cin >> x >> s >> e;
		if (x == 'R') {
			imos_lazy[s]++;
			imos_lazy[e + 1]--;
		}
		if (x == 'D') {
			imos_lazy[s]--;
			imos_lazy[e + 1]++;
		}
		if (x == 'H') {
			imos2[s]++;
			imos2[e + 2]++;
			if ((e - s) & 1) {
				imos2[(s + e + 1) / 2]--;
				imos2[(s + e + 1) / 2 + 1]--;
			} else {
				imos2[(s + e) / 2 + 1] -= 2;
			}
		}
		if (x == 'V') {
			imos2[s]--;
			imos2[e + 2]--;
			if ((e - s) & 1) {
				imos2[(s + e + 1) / 2]++;
				imos2[(s + e + 1) / 2 + 1]++;
			} else {
				imos2[(s + e) / 2 + 1] += 2;
			}
		}
	}
	for (int i = 1; i <= n; i++) imos1[i] = imos1[i - 1] + imos2[i];
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		cur += imos1[i] + imos_lazy[i];
		cout << cur << '\n';
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
}