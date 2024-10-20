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
	int hol = 0, jak = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i % 2) hol += a[i];
		else jak += a[i];
	}
	if (n == 3) {
		if (jak > hol) cout << "-1";
		else cout << hol - jak;
	} else {
		cout << abs(hol - jak);
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}