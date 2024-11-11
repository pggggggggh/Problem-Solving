#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	if (n == 1) {
		cout << "? 1 1" << endl;
		int len;
		cin >> len;
		vector<int> a(len + 1);
		for (int i = 1; i <= len; i++) cin >> a[i];
		cout << "! " << len << ' ';
		for (int i = 1; i <= len; i++) cout << a[i] << ' ';
		cout << '\n';
		return;
	}
	vector<vector<int>> anss;
	auto query = [&](int l, int r) {
		cout << "? " << (r - l + 1) * 2 << ' ';
		for (int i = l; i <= r; i++) cout << i << ' ' << i << ' ';
		cout << endl;
		int len;
		cin >> len;
		int fooptr = -1;
		set<int> st;
		vector<int> ans;
		for (int i = 1; i <= len; i++) {
			int x;
			cin >> x;
			if (i < fooptr) continue;
			if (st.count(x)) {
				fooptr = i + ans.size();
				anss.push_back(ans);
				ans.clear();
				st.clear();
			}
			if (i >= fooptr) {
				st.insert(x);
				ans.push_back(x);
			}
		}
	};

	if (n == 2) {
		query(1, 1);
		query(2, 2);
	} else {
		int mid = 1 + n >> 1;
		query(1, mid - 1);
		query(mid, mid);
		query(mid + 1, n);
	}

	cout << "! ";
	for (auto& ans : anss) {
		cout << ans.size() << ' ';
		for (auto& x : ans) cout << x << ' ';
	}
	cout << endl;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}