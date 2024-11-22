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
	vector<int> a(n + 1);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] %= k;
		sum += a[i];
	}
	if (sum % k) {
		cout << "blobsad";
		return;
	}
	int s = -1, cur = 0;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] % k == 0 && s == -1) continue;
		else if (s == -1) {
			s = i;
			cur = a[i];
			continue;
		}
		if (cur / k != (cur + a[i]) / k) {
			int toadd = k - (cur % k);
			a[i] -= toadd;
			int sz = i - s + 1;
			vector<int> b(sz + 1), psum(sz + 1);
			b[sz] = toadd;
			for (int j = 1; j < sz; j++) b[j] = a[s + j - 1];
			int ccur = 0;
			for (int j = 1; j <= sz; j++) {
				psum[j] = psum[j - 1] + b[j];
				ccur += b[j] * (j - 1);
			}
			int mn = ccur;
			for (int j = 2; j <= sz; j++) {
				ccur += psum[j - 1];
				ccur -= psum[sz] - psum[j - 1];
				mn = min(mn, ccur);
			}
			res += mn;
			cur = 0;
			if (a[i] % k == 0) s = -1;
			else {
				cur = a[i];
				s = i;
			}
		} else {
			cur += a[i];
		}
	}
	cout << res;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}