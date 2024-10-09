#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define all(v) (v).begin(), (v).end()
#define int long long
#define pbds                                           \
	tree<int, null_type, less_equal<int>, rb_tree_tag, \
	     tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
using pi = pair<int, int>;

void p_erase(pbds &p, int val) {
	int idx = p.order_of_key(val);
	pbds::iterator it = p.find_by_order(idx);
	if (*it == val) p.erase(it);
}

void solve() {
	int n;
	set<int> s;
	vector<int> a(200005);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	set<int> p;
	for (int i = 1; i <= 1300000; i++) {
		if (s.count(i) == 0) {
			p.insert(i);
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		int num = *p.lower_bound(a[x]);
		p.insert(a[x]);
		p.erase(num);
		a[x] = num;
		cout << num << '\n';
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}