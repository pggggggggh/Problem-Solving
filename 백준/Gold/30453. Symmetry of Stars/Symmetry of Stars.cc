#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define ll long long
using namespace std;
using pi = pair<int, int>;

constexpr int MOD = 59999971;

inline ll hsh(pi& p)
{
	return (((ll)(p.first + 1234567890) * 1234567890 + p.second + 1234567890) % MOD + MOD) % MOD;
}

short cnt[59999971];

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
			auto& ret = cnt[hsh(p)];
			if (i == j) ret += 1;
			else ret += 2;
			res = max(res, (int)ret);
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