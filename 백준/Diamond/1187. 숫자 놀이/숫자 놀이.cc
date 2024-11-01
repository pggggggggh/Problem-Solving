#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	std::random_device rd;
	std::mt19937 gen(rd());

	int n;
	cin >> n;
	vector<int> a(2 * n - 1);
	for (int i = 0; i < 2 * n - 1; i++) cin >> a[i];
	sort(all(a));
	int tc = 5000;
	while (tc--) {
		vector<int> ar(n);
		sample(all(a), ar.begin(), n, gen);
		if (accumulate(all(ar), 0) % n == 0) {
			for (auto& x : ar) cout << x << ' ';
			return;
		}
	}
	deque<int> dq;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		dq.push_back(a[i]);
		cur += a[i];
	}
	if (cur % n == 0) {
		for (auto& x : dq) cout << x << ' ';
		return;
	}
	for (int i = n; i < 2 * n - 1; i++) {
		cur -= dq.front();
		dq.pop_front();
		cur += a[i];
		dq.push_back(a[i]);

		if (cur % n == 0) {
			for (auto& x : dq) cout << x << ' ';
			return;
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}