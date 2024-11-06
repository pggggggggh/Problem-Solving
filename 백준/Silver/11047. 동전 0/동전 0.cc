#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(all(a));
	reverse(all(a));
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += k / a[i];
		k %= a[i];
	}
	cout << res;
}