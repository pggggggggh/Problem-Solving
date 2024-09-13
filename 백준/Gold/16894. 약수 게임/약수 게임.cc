#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int,int>;

signed main() {
    int n, cnt = 0;
    cin >> n;
    if (n == 1) {
        cout << "koosaga";
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
    }
    if (n > 1) cnt++;
    cout << (cnt != 2 ? "koosaga" : "cubelover");
}
