#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int,int>;

int m, n;
int a[5005];
bitset<50001> bs;

signed main() {
    cin >> m >> n;
    bs[0] = 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        bs |= (bs << x);
        bs[0] = 1;
    }
    for (int i = m; i >= 0; i--) {
        if (bs[i]) {
            cout << i;
            return 0;
        }
    }
}
