#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;

signed main() {
    int n, t, p;
    int a[6];
    cin >> n;
    for (int i = 0; i < 6; i++) {
        cin >> a[i];
    }
    cin >> t >> p;
    int cnt = 0;
    for (int i = 0; i < 6; i++) {
        cnt += (a[i] + (t - 1)) / t;
    }
    cout << cnt << '\n' << n / p << ' ' << n % p;
}
