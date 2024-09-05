#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define MOD 1000001
using pi = pair<int, int>;

int dp[2][201][201][201]; // col까지 써서 left개 남고, ones,twos로 배치 가능한 경우의 수
int n, m, k;

signed main() {
    cin >> n >> m >> k;
    dp[0][k][0][0] = 1;
    for (int col = 0; col <= m; col++) {
        int cur = col % 2, nxt = 1 - col % 2;
        for (int left = 0; left <= k; left++) {
            for (int ones = 0; ones <= k; ones++) {
                for (int twos = 0; twos <= k; twos++) {
                    int zeros = n - ones - twos;
                    if (zeros < 0) continue;
                    if (twos + 2 <= n && left >= 2 && zeros >= 2)
                        dp[nxt][left - 2][ones][twos + 2] =
                        (dp[nxt][left - 2][ones][twos + 2] + zeros * (zeros - 1) / 2 * dp[cur][left][ones][twos] %
                         MOD) % MOD;
                    if (ones + 1 <= n && left >= 1 && zeros >= 1)
                        dp[nxt][left - 1][ones + 1][twos] =
                        (dp[nxt][left - 1][ones + 1][twos] + zeros * dp[cur][left][ones][twos] %
                         MOD) % MOD;
                    if (twos + 1 <= n && left >= 1 && ones >= 1)
                        dp[nxt][left - 1][ones - 1][twos + 1] =
                        (dp[nxt][left - 1][ones - 1][twos + 1] + ones * dp[cur][left][ones][twos] %
                         MOD) % MOD;
                    dp[nxt][left][ones][twos] = (dp[nxt][left][ones][twos] + dp[cur][left][ones][twos]) % MOD;
                }
            }
        }
        if (col == m) break;
        for (int left = 0; left <= k; left++) {
            for (int ones = 0; ones <= k; ones++) {
                for (int twos = 0; twos <= k; twos++) {
                    dp[cur][left][ones][twos] = 0;
                }
            }
        }
    }
    int res = 0;
    for (int ones = 0; ones <= k; ones++) {
        for (int twos = 0; twos <= k; twos++) {
            res = (res + dp[m % 2][0][ones][twos]) % MOD;
        }
    }
    cout << res;
}
