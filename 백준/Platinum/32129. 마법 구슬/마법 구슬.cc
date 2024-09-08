#include <bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
using pi = pair<int, int>;

int n, q;
int a[500005];

void roll() {
    for (int i = 1; i <= n; i++) {
        if (a[i] <= a[i + 1]) {
            a[i]++;
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[n + 1] = 1e18;
    while (q--) {
        int x, y;
        cin >> x;
        if (x == 1) {
            cin >> y;
            while (y--) roll();
        } else {
            cout << a[1] << '\n';
        }
    }
}
