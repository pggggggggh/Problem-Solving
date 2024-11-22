#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	vector<int> isp(4100005, 1);
	vector<int> p;
	for (int i = 2; i <= 4100000; i++) {
		if (!isp[i]) continue;
		p.push_back(i);
		for (int j = i * 2; j <= 4100000; j += i) isp[j] = 0;
	}
	int n;
	cin >> n;
	int sum = 0, res = 0;
	int r = 0;
	for (int l = 0; p[l] <= n; l++) {
		while (p[r] <= n && sum < n) sum += p[r++];
		if (sum == n) res++;
		sum -= p[l];
	}
	cout << res;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}