#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

int hsh(pi p)
{
	return (((p.first + 1234567890) * 1234567890 + p.second + 1234567890) % 99999989 + 99999989) % 99999989;
}

unsigned cnt[100000000];

void solve()
{
	int n;
	cin >> n;
	vector<pi> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			pi p = { a[i].first + a[j].first, a[i].second + a[j].second };
			cnt[hsh(p)]++;
			res = max(res, (int)cnt[hsh(p)]);
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