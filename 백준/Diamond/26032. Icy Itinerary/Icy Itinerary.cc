#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, m;
	cin >> n >> m;
	map<pi, int> adj;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		adj[{ x, y }] = 1;
		adj[{ y, x }] = 1;
	}
	int sflag = 0;
	if (adj[{ 1, 2 }]) sflag = 1;
	list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	auto change = prev(lst.end());
	for (int i = 3; i <= n; i++) {
		if (change == prev(lst.end())) {
			if (adj[{ lst.back(), i }] != sflag) {
				change = prev(lst.end());
				lst.push_back(i);
			} else {
				lst.push_back(i);
				change++;
			}
		} else {
			if (adj[{ *change, i }] == sflag) { // 오른쪽
				change = lst.insert(next(change), i);
				if (adj[{ *change, *next(change) }] == sflag) change = next(change);
			} else {
				change = lst.insert(change, i);
				if (adj[{ *change, *(prev(change)) }] != sflag) change = prev(change);
				if (change == lst.begin()) {
					sflag = 1 - sflag;
					change = prev(lst.end());
				}
			}
		}
	}
	for (auto it = lst.begin(); it != lst.end(); it++) {
		cout << *it << ' ';
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}