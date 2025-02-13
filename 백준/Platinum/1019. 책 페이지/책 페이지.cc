#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	vector<int> ans(10);
	for (int jari = 1; jari <= n; jari *= 10) {
		for (int i = 0; i <= 9; i++) {
			int num = (n % (jari * 10)) / jari;
			int repeat = n / (jari * 10) + 1;
			if (i == 0) repeat--;
			if (i < num) {
				ans[i] += repeat * jari;
			} else {
				repeat--;
				ans[i] += repeat * jari;
				if (i == num) ans[i] += n % jari + 1;
			}
		}
	}
	for (int i = 0; i < 10; i++) cout << ans[i] << ' ';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}