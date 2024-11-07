#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define ll long long
using namespace std;
using pi = pair<int, int>;

inline ll hsh(pi p)
{
	return (((ll)(p.first + 1234567890) * 1234567890 + p.second + 1234567890) % 99999989 + 99999989) % 99999989;
}

short cnt[100000000];

void solve()
{
	int n;
	cin >> n;
	vector<pi> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			const pi p = { a[i].first + a[j].first, a[i].second + a[j].second };
			auto& ref = cnt[hsh(p)];
			if (i == j) ref += 1;
			else ref += 2;
			res = max(res, (int)ref);
		}
	}
	cout << res;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}