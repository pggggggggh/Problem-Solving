#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int,int>;

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cur ^= a[i];
    }
    if (cur) cout << "koosaga";
    else cout << "cubelover";
}
