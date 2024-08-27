#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = array<int, 2>;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c;
    cin >> a >> b >> c;
    int res = 1, piv = a;
    while (b) {
        if (b & 1) res *= piv;
        piv *= piv;
        res %= c;
        piv %= c;
        b >>= 1;
    }
    cout << res;
}
