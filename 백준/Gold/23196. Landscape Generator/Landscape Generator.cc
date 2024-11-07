#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> amos(n + 3), bmos(n + 3);
	while (k--) {
		int s, e;
		char x;
		cin >> x >> s >> e;
		int mid = s + e >> 1;
		if (x == 'H') {
			amos[s]++;
			amos[mid + 1] -= 2;
			amos[e + 1]++;
			bmos[s] -= s - 1;
			if ((e - s + 1) % 2) {
				bmos[mid + 1] += mid * 2;
				bmos[e + 1] -= mid * 2;
			} else {
				bmos[mid + 1] += mid * 2 + 1;
				bmos[e + 1] -= mid * 2 + 1;
			}
			bmos[e + 1] += s - 1;
		}
		if (x == 'V') {
			amos[s]--;
			amos[mid + 1] += 2;
			amos[e + 1]--;
			bmos[s] += s - 1;
			if ((e - s + 1) % 2) {
				bmos[mid + 1] -= mid * 2;
				bmos[e + 1] += mid * 2;
			} else {
				bmos[mid + 1] -= mid * 2 + 1;
				bmos[e + 1] += mid * 2 + 1;
			}
			bmos[e + 1] -= s - 1;
		}
		if (x == 'R') {
			bmos[s]++;
			bmos[e + 1]--;
		}
		if (x == 'D') {
			bmos[s]--;
			bmos[e + 1]++;
		}
	}
	int a = 0, b = 0;
	for (int i = 1; i <= n; i++) {
		a += amos[i], b += bmos[i];
		cout << a * i + b << '\n';
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
}