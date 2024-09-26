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
	int cur = -1, dir = 1;
	while (1) {
		// 현재 cur에 화살표 그어놓은 상태
		if (dir == 1) {
			if (a[cur + 1] == 0)
				dir *= -1;
			else
				cur++;
		} else {
			if (cur == 0) {
				if (a[cur] == 0)
					break;
				else
					dir *= -1;
			} else if (a[cur - 1] == 1) {
				if (a[cur] > 0)
					dir *= -1;
				else
					cur--;
			} else {
				cur--;
			}
		}
		a[cur] -= 1;
		cout << (dir == 1 ? 'R' : 'L');
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}