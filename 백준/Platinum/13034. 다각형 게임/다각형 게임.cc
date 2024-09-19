#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int,int>;

int g[1005] = {0, 0, 1};

signed main() {
    int n;
    cin >> n;
    for (int i = 3; i <= n; i++) {
        vector<bool> chk(i + 1);
        for (int j = 0; j <= (i - 2) / 2; j++) {
            chk[g[j] ^ g[(i - 2) - j]] = 1;
        }
        for (int j = 0;; j++) {
            if (chk[j] == 0) {
                g[i] = j;
                break;
            }
        }
    }
    cout << (g[n] > 0 ? 1 : 2);
}
