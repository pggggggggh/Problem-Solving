#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int x;
	array<int, 4> ar;
	cin >> x >> ar[0] >> ar[1] >> ar[2] >> ar[3];
	int tot = ar[0] + ar[1] + ar[2] + ar[3];

	vector<array<int, 4>> ans;
	for (int d = 0; d < 4; d++) {
		array<int, 4> cur = ar;
		vector<array<int, 4>> res;
		res.push_back(cur);

		// 짝수로
		if ((tot - cur[d]) % 2 == 1) {
			int a = -1;
			for (int i = 0; i < 4; i++)
				if (i != d && (a == -1 || cur[i] > cur[a])) a = i;
			int b = -1, c;
			for (int i = 0; i < 4; i++) {
				if (i != d && i != a) {
					if (b == -1) b = i;
					else c = i;
				}
			}
			if (cur[b] < cur[c]) swap(b, c);
			cur[d]--, cur[a]--, cur[c] += 2;
			res.push_back(cur);
		}

		// a <= b+c 만들기
		int a = -1;
		for (int i = 0; i < 4; i++)
			if (i != d && (a == -1 || cur[i] > cur[a])) a = i;
		int b = -1, c;
		for (int i = 0; i < 4; i++) {
			if (i != d && i != a) {
				if (b == -1) b = i;
				else c = i;
			}
		}
		while (cur[a] > cur[b] + cur[c]) {
			if (cur[b]) cur[a]--, cur[b]--, cur[c] += 2;
			else if (cur[c]) cur[a]--, cur[c]--, cur[b] += 2;
			else {
				if (cur[d] == 0) goto fin;
				else {
					cur[d] -= 1, cur[a] -= 1, cur[b] += 2;
					res.push_back(cur);
					cur[d] -= 1, cur[a] -= 1, cur[b] += 2;
				}
			}
			res.push_back(cur);
		}
		while (cur[a]) {
			if (cur[b] > cur[c]) cur[a]--, cur[b]--, cur[d] += 2;
			else cur[a]--, cur[c]--, cur[d] += 2;
			res.push_back(cur);
		}
		while (cur[b]) {
			cur[b]--, cur[c]--, cur[d] += 2;
			res.push_back(cur);
		}

	fin:
		if (ans.empty() || res.size() < ans.size()) ans = res;
		// cout << a << ' ' << b << ' ' << c << ' ' << d << ":\n";
		// for (auto& r : res) {
		// 	for (int i = 0; i < 4; i++) cout << r[i] << ' ';
		// 	cout << '\n';
		// }
		// cout << "------\n";
	}
	for (auto& a : ans) {
		for (int i = 0; i < 4; i++) cout << a[i] << ' ';
		cout << '\n';
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}