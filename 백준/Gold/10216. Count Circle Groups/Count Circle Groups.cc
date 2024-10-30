#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

struct union_find {
	int n;
	vector<int> par;

	union_find(int n)
	    : n(n)
	{
		par.resize(n);
		for (int i = 0; i < n; i++) par[i] = i;
	}

	int find(int x)
	{
		if (par[x] == x) return x;
		return par[x] = find(par[x]);
	}

	void uni(int x, int y)
	{
		x = find(x);
		y = find(y);
		if (x == y) return;
		par[y] = x;
	}
};

struct point {
	int x, y;
};

int dist2(point& a, point& b)
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void solve()
{
	int n;
	cin >> n;
	vector<point> a(n);
	vector<int> r(n);
	union_find uf(n);
	for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y >> r[i];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (dist2(a[i], a[j]) <= (r[i] + r[j]) * (r[i] + r[j])) uf.uni(i, j);
		}
	}
	set<int> s;
	for (int i = 0; i < n; i++) {
		s.insert(uf.find(i));
	}
	cout << s.size() << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();
}