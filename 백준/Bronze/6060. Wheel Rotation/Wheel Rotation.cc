#include <bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
using pi = pair<int, int>;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i < n; i++) {
        int s, e, x;
        cin >> s >> e >> x;
        res += x;
    }
    cout << res % 2;
}
