#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

constexpr int m1 = 211;
constexpr int m2 = 223;
constexpr int m3 = 307;
constexpr int inf = 2000000000LL;

inline int hsh(pi& p)
{
	int h = (p.first + inf) * inf + p.second + inf;
	return (h % m1) * m3 * m3 + (h % m2) * m3 + h % m3;
}

short cnt[20000000];

void solve()
{
	int n;
	cin >> n;
	vector<pi> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			pi p = { a[i].first + a[j].first, a[i].second + a[j].second };
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