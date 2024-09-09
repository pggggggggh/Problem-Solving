#include <bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
using pi = pair<int, int>;

int n, k;
int s[20];
int dp[20][100000];

int recur(int past, int state) {
    int &res = dp[past + 1][state];
    if (res != -1) return res;
    if (state == (1LL << n) - 1) return res = 1;
    res = 0;
    for (int i = 0; i < n; i++) {
        if ((state >> i) & 1) continue;
        if (past != -1 && abs(s[past] - s[i]) <= k) continue;
        res += recur(i, state | (1LL << i));
    }
    return res;
}

signed main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> s[i];
    memset(dp, -1, sizeof(dp));
    cout << recur(-1, 0);
}
