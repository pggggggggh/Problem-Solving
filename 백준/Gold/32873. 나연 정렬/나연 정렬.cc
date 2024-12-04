#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> st;
	for (int i = 0; i < n; i++) {
		int x;
		auto it = lower_bound(all(st), a[i]);
		if (it == st.end()) st.push_back(a[i]);
		else *it = a[i];
	}
	cout << st.size();
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}