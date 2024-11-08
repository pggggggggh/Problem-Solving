#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

int bkt = 300;
vector<int> ys[100005];

void solve()
{
	int n;
	cin >> n;
	vector<pi> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		ys[a[i].first].push_back(a[i].second);
	}
	vector<vector<int>*> bigs, smalls;
	for (int i = 0; i <= 100000; i++) {
		if (ys[i].empty()) continue;
		sort(all(ys[i]));
		if (ys[i].size() < bkt) smalls.push_back(&ys[i]);
		else bigs.push_back(&ys[i]);
	}
	int res = 0;

	// small & small
	unordered_map<int, int> mp;
	for (auto& p : smalls) {
		auto& small = *p;
		for (int i = 0; i < small.size(); i++) {
			for (int j = i + 1; j < small.size(); j++) {
				mp[small[i] * 100005 + small[j]]++;
			}
		}
	}
	for (auto& [_, cnt] : mp) res += cnt * (cnt - 1) / 2;

	// big & big
	for (int i = 0; i < bigs.size(); i++) {
		auto& big1 = *bigs[i];
		for (int j = i + 1; j < bigs.size(); j++) {
			auto& big2 = *bigs[j];
			int ptr1 = 0, ptr2 = 0, cur = 0;
			while (1) {
				if (big1[ptr1] == big2[ptr2]) cur++;
				if (ptr2 == big2.size() - 1 || big1[ptr1] < big2[ptr2]) ptr1++;
				else ptr2++;
				if (ptr1 == big1.size()) break;
			}
			res += cur * (cur - 1) / 2;
		}
	}

	// small & big
	for (int i = 0; i < bigs.size(); i++) {
		auto& big = *bigs[i];
		for (int j = 0; j < smalls.size(); j++) {
			auto& small = *smalls[j];
			int cur = 0;
			for (auto& x : small) {
				cur += binary_search(all(big), x);
			}
			res += cur * (cur - 1) / 2;
		}
	}

	cout << res;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}