#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	vector<int> zero, one, two;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x % 3 == 0) zero.push_back(x);
		else if (x % 3 == 1) one.push_back(x);
		else two.push_back(x);
	}
	if ((one.size() && two.size() && zero.size() == 0) || zero.size() > (n + 1) / 2) {
		cout << -1;
		return;
	}
	list<int> lst;
	for (int i = 0; i < (int)zero.size() - 1; i++) {
		lst.push_back(zero[i]);
		if (!one.empty()) {
			lst.push_back(one.back());
			one.pop_back();
		} else {
			lst.push_back(two.back());
			two.pop_back();
		}
	}
	if (zero.size()) lst.push_back(zero.back());
	for (auto& x : one) lst.push_front(x);
	for (auto& x : two) lst.push_back(x);
	for (auto& x : lst) cout << x << ' ';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}