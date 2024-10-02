#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve() {
	vector<int> g(505);
	int k1, k2, k3;
	cin >> k1 >> k2 >> k3;
	for (int i = 1; i <= 500; i++) {
		vector<int> vis(5);
		if (i - k1 >= 0) vis[g[i - k1]] = 1;
		if (i - k2 >= 0) vis[g[i - k2]] = 1;
		if (i - k3 >= 0) vis[g[i - k3]] = 1;
		for (int j = 0; j <= 3; j++) {
			if (!vis[j]) {
				g[i] = j;
				break;
			}
		}
	}
	for (int t = 0; t < 5; t++) {
		int a, b;
		cin >> a >> b;
		cout << (g[a] ^ g[b] ? "A" : "B") << '\n';
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}