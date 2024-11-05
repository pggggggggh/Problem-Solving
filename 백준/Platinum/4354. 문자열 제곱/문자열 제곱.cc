#include <bits/stdc++.h>
#define int long long
using namespace std;

string s;

void solve()
{
	int n = s.size();
	vector<int> fail(n);
	for (int i = 1, j = 0; i < n; i++) {
		while (j > 0 && s[i] != s[j]) j = fail[j - 1];
		if (s[i] == s[j]) fail[i] = ++j;
	}
	if (n % (n - fail[n - 1])) cout << 1 << '\n';
	else cout << n / (n - fail[n - 1]) << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> s;
		if (s == ".") break;
		solve();
	}
}