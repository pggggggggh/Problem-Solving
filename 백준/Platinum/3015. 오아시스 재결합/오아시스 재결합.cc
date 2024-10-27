#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<pi> stk;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int recover = 0;
		while (!stk.empty() && stk.back().first <= a[i]) {
			if (stk.back().first == a[i]) recover = stk.back().second;
			ans += stk.back().second;
			stk.pop_back();
		}
		if (!stk.empty() && stk.back().first > a[i]) ans += 1;
		stk.push_back({ a[i], recover + 1 });
	}
	cout << ans;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}