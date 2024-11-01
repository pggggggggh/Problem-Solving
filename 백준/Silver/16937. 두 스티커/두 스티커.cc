#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int h, w, n;
	cin >> h >> w >> n;
	vector<pi> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int t = 0; t < 2; t++) {
			swap(a[i].first, a[i].second);
			if (a[i].first > h || a[i].second > w) continue;
			for (int j = i + 1; j < n; j++) {
				for (int tt = 0; tt < 2; tt++) {
					swap(a[j].first, a[j].second);
					if (a[j].first > h || a[j].second > w) continue;
					if (a[i].first + a[j].first <= h || a[i].second + a[j].second <= w) res = max(res, a[i].first * a[i].second + a[j].first * a[j].second);
				}
			}
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