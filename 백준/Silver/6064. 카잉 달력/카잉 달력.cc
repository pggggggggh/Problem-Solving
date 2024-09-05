#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define MOD 20070713
using pi = pair<int, int>;

int euclid(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int d = euclid(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int crt(int a, int m, int b, int n) {
    if (m < n) swap(a, b), swap(m, n);
    int x, y, g = euclid(m, n, x, y);
    if ((a - b) % g != 0) return -1; // no solution
    x = (b - a) % n * x % n / g * m + a;
    return x < 0 ? x + m * n / g : x;
}

void solve() {
    int m, n, x, y;
    cin >> m >> n >> x >> y;
    int res = crt(x, m, y, n);
    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
