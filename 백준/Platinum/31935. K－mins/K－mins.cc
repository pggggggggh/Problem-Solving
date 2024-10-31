#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	vector<pi> p;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p.emplace_back(a[i], i);
	}
	sort(all(p));

	int res = 0;
	set<int> st;
	for (auto& [_, idx] : p) {
		st.insert(idx);
		vector<int> l, r;
		auto itl = st.lower_bound(idx);
		auto itr = st.lower_bound(idx);
		while (1) {
			l.push_back(*itl);
			if (itl == st.begin()) break;
			if (l.size() == k + 1) break;
			itl--;
		}
		while (itr != st.end()) {
			r.push_back(*itr);
			if (r.size() == k + 1) break;
			itr++;
		}
		vector<int> ll(l.size()), rr(r.size());
		r.push_back(n + 1);
		for (int i = 0; i < r.size() - 1; i++) rr[i] = r[i + 1] - r[i];
		l.push_back(0);
		for (int i = 0; i < l.size() - 1; i++) ll[i] = l[i] - l[i + 1];
		for (int i = 0; i < rr.size(); i++) {
			if (k - 1 - i >= 0 && k - 1 - i < ll.size()) res += a[idx] * rr[i] * ll[k - 1 - i];
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