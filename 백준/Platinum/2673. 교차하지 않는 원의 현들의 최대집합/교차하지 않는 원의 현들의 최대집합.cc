#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define MOD 1000001
using pi = pair<int, int>;

int dp[105][105];
int is[105][105];

int recur(int l, int r) {
    int &res = dp[l][r];
    if (res != -1) return res;
    res = is[l][r];
    for (int i = l; i < r; i++) {
        res = max(res, recur(l, i) + recur(i + 1, r) + is[l][r]);
    }
    return res;
}

signed main() {
    int n;
    cin >> n;
    vector<pi> a(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        is[x][y] = 1;
    }
    memset(dp, -1, sizeof(dp));
    cout << recur(1, 100);
}
