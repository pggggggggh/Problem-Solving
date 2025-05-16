#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

string a;
int n;
int dp[1505][1505][3]; // 0,1,2 : 2면 ?, 인 상태에서 준범이 받음

void solve()
{
	cin >> a;
	n = a.size();
	a = '$' + a;
	int qmpos = -1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == '?') qmpos = i;
	}

	for (int len = 0; len <= n - 1; len++) {
		for (int s = 1; s + len <= n; s++) {
			int e = s + len;
			for (int qm = 0; qm < 3; qm++) {
				if (qmpos != -1) {
					if (qm == 0) a[qmpos] = '0';
					else if (qm == 1) a[qmpos] = '1';
				}

				if (qm == 2 && qmpos != -1) dp[s][e][qm] = !dp[s][e][0] || !dp[s][e][1];
				if (s == e && (qmpos != s || qm != 2)) {
					dp[s][e][qm] = 1;
				}
				if (!dp[s][e][qm]) {
					for (int i = s; i < e; i++) {
						if (a[i] == '?' || a[i] != a[s]) break;
						if (dp[i + 1][e][qm] == 0) {
							// cout << s << ' ' << e << ' ' << qm << "influcenced by " << i + 1 << ' ' << e << ' ' << qm << '\n';
							dp[s][e][qm] = 1;
							break;
						}
					}
				}
				if (!dp[s][e][qm]) {
					for (int i = e; i > s; i--) {
						if (a[i] == '?' || a[i] != a[e]) break;
						if (dp[s][i - 1][qm] == 0) {
							dp[s][e][qm] = 1;
							break;
						}
					}
				}

				if (qmpos != -1) {
					a[qmpos] = '?';
				}
			}
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = i; j <= n; j++) {
	// 		for (int qm = 0; qm < 3; qm++) {
	// 			cout << i << ' ' << j << ' ' << qm << ':' << dp[i][j][qm] << '\n';
	// 		}
	// 	}
	// }
	cout << dp[1][n][2];
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}