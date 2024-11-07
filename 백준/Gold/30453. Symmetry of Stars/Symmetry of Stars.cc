#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

constexpr int m1 = 5003;
constexpr int m2 = 5021;
constexpr int m3 = 2000000000LL;

inline int hsh(pi& p)
{
	int h = (p.first + m3) * m3 + p.second + m3;
	return (h % m1) * m2 + h % m2;
}

short cnt[30000000];

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