#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	set<int> st;
	int res = 0;
	int r = 0;
	for (int l = 0; l < n; l++) {
		st.insert(a[l]);
		r = max(l, r);
		while (r < n - 1 && st.count(a[r + 1]) == 0) {
			r++;
			st.insert(a[r]);
		}
		st.erase(a[l]);
		res += r - l + 1;
	}
	cout << res;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}