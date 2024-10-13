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

	while (1) {
		for (int i = 0; i < 4; i++) cout << ar[i] << ' ';
		cout << '\n';

		array<int, 4> idx = { 0, 1, 2, 3 };
		sort(all(idx), [&](int x, int y) {
			return ar[x] < ar[y];
		});
		if (ar[idx[2]] == 0) break;
		if ((tot - ar[idx[3]]) % 2) { // 짝수로 만들기
			ar[idx[2]]--, ar[idx[3]]--, ar[idx[0]] += 2;
			continue;
		}
		if (ar[idx[1]] == 0) {
			ar[idx[2]]--, ar[idx[3]]--, ar[idx[0]] += 2;
			continue;
		}
		if (ar[idx[0]] + ar[idx[1]] < ar[idx[2]]) { // a+b < c
			ar[idx[1]]--, ar[idx[2]]--, ar[idx[0]] += 2;
			continue;
		}
		ar[idx[1]]--, ar[idx[2]]--, ar[idx[3]] += 2;
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}