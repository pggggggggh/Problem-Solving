#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

struct point {
	int x, y;
};

int hypot(point p1, point p2)
{
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int ccw(point p1, point p2, point p3)
{
	return p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p2.x * p1.y - p3.x * p2.y - p1.x * p3.y;
}

void solve()
{
	int n;
	cin >> n;
	vector<point> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
	sort(all(a), [&](point& p1, point& p2) {
		if (p1.y == p2.y) return p1.x < p2.x;
		return p1.y < p2.y;
	});
	sort(a.begin() + 1, a.end(), [&](point& p1, point& p2) -> int {
		int c = ccw(a[0], p1, p2);
		if (c == 0) return hypot(a[0], p1) < hypot(a[0], p2);
		return c > 0;
	});
	vector<point> stk;
	for (int i = 0; i < n; i++) {
		while (stk.size() >= 2 && ccw(stk[stk.size() - 2], stk.back(), a[i]) <= 0)
			stk.pop_back();
		stk.push_back(a[i]);
	}
	cout << stk.size();
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}