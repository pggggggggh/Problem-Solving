#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n, q;
	cin >> n >> q;
	vector<pi> seg;
	vector<int> ss, es;
	vector<int> a(n + 1), psum(n + 1);
	int s = 1;
	vector<int> truesegs;
	for (int i = 1; i <= n; i++) {
		string x;
		cin >> x;
		if (i % 2 == 1) {
			a[i] = (x == "true");
		} else {
			if (x == "or") {
				seg.push_back({ s, i - 1 });
				s = i + 1;
			}
		}
		psum[i] = psum[i - 1] + a[i];
	}
	seg.push_back({ s, n });
	for (auto& [x, y] : seg) {
		ss.push_back(x);
		es.push_back(y);
		int sibal = 0;
		for (int i = x; i <= y; i += 2) {
			if (a[i] == 0) {
				sibal = 1;
				break;
			}
		}
		if (!sibal) truesegs.push_back(x);
	}

	while (q--) {
		int s, e;
		string x;
		cin >> s >> e >> x;
		int segs = *prev(upper_bound(all(ss), s));
		int sege = *lower_bound(all(es), e);
		if (!truesegs.empty() && (truesegs[0] < segs || sege < truesegs.back())) {
			if (x == "true") cout << "Y";
			else cout << "N";
		} else {
			if (psum[sege] - psum[e] + psum[s - 1] - psum[segs - 1] != (s - segs) / 2 + (sege - e) / 2) {
				if (x == "false") cout << "Y";
				else cout << "N";
			} else cout << "Y";
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}