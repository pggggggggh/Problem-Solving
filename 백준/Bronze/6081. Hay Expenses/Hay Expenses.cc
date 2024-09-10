#include <bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
using pi = pair<int, int>;

signed main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), psum(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << psum[y] - psum[x - 1] << '\n';
    }
}
