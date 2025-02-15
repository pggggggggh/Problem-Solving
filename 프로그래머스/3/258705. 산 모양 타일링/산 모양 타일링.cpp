#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;

int dp[100005][2]; // 1 : 사다리꼴로 넘어온 경우만

int solution(int n, vector<int> tops) {
    dp[0][0] = 1;
    for (int i=1;i<=n;i++) {
        if (tops[i-1] == 1) {
            dp[i][0] = (dp[i-1][0]*3+dp[i-1][1]*2)%MOD;
            dp[i][1] = (dp[i-1][0]+dp[i-1][1])%MOD;
        } else {
            dp[i][0] = (dp[i-1][0]*2+dp[i-1][1])%MOD;
            dp[i][1] = (dp[i-1][0]+dp[i-1][1])%MOD;
        }
    }
    return (dp[n][0]+dp[n][1])%MOD;
}