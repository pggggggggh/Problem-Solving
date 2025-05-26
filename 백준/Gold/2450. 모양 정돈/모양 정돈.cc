#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

vector<int> a, b;
int n;

int sex()
{
	vector<vector<int>> cnt(3, vector<int>(3));
	int m = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) continue;
		cnt[a[i]][b[i]]++;
		m++;
	}
	int two = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 3; j++) {
			two += min(cnt[i][j], cnt[j][i]);
		}
	}
	return m - (two + (m - two * 2) / 3);
}

void solve()
{
	cin >> n;
	a.resize(n);
	int cnt[3] = { 0 };
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		cnt[a[i]]++;
	}
	vector<int> p = { 0, 1, 2 };
	int ans = 1e18;
	do {
		b.clear();
		for (auto& x : p) {
			for (int i = 0; i < cnt[x]; i++) b.push_back(x);
		}
		ans = min(ans, sex());
	} while (next_permutation(all(p)));
	cout << ans;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}