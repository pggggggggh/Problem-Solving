#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;

int p[105] = {0, 1, 1, 1, 2};

signed main() {
    for (int i = 5; i <= 100; i++) {
        p[i] = p[i - 5] + p[i - 1];
    }
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << p[n] << '\n';
    }
}
