#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	priority_queue<int> mx;
	priority_queue<int, vector<int>, greater<int>> mn;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (i % 2 == 0) mx.push(x);
		else mn.push(x);
		if (mx.size() * mn.size() != 0 && mx.top() > mn.top()) {
			int mxtop = mx.top();
			int mntop = mn.top();
			mx.pop();
			mn.pop();
			mx.push(mntop);
			mn.push(mxtop);
		}
		cout << mx.top() << '\n';
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}