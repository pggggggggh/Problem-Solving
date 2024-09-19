#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int,int>;

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int res = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        res ^= a[i];
    }
    cout << (res > 0 ? "koosaga" : "cubelover");
}
