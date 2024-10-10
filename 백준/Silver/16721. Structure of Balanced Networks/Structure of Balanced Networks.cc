#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

struct union_find {
	int n;
	vector<int> par;

	union_find(int n) {
		this->n = n;
		for (int i = 0; i < n; i++) par.push_back(i);
	}

	int find(int x) {
		if (x == par[x]) return x;
		return par[x] = find(par[x]);
	}

	void uni(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return;
		par[y] = x;
	}
};

void solve() {
	int n;
	cin >> n;
	union_find uf(n);
	char x;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> x;
			if (x == '+') uf.uni(i, j);
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		if (uf.find(x) == uf.find(y))
			cout << "+\n";
		else
			cout << "-\n";
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}