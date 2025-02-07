#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	int now = 0, mx = 0;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		if (a[i] == b[i]) now++;
	}
	mx = now;
	for (int i = n; i >= 2; i--) {
		for (int j = 1; j <= i - 1; j++) {
			if (a[j] > a[j + 1]) {
				if (a[j] == b[j]) now--;
				if (a[j + 1] == b[j + 1]) now--;
				swap(a[j], a[j + 1]);
				if (a[j] == b[j]) now++;
				if (a[j + 1] == b[j + 1]) now++;
			}
			mx = max(mx, now);
		}
	}
	cout << mx / n;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}