#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);  // a[n] = 0
	for (int i = 0; i < n; i++) cin >> a[i];
	int cur = 0;
	while (1) {
		while (a[cur] > 0) {
			cout << 'R';
			a[cur]--;
			cur++;
		}
		while (cur > 0 && (a[cur - 1] > 1 || a[cur] == 0)) {
			cout << 'L';
			cur--;
			a[cur]--;
		}
		if (cur == 0 && a[cur] == 0) break;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}