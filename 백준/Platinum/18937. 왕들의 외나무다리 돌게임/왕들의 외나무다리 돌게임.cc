#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int,int>;

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int ns = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ns ^= (a[i] - 2);
    }
    string s;
    cin >> s;
    if (s[0] == 'W') {
        cout << (ns > 0 ? "Whiteking" : "Blackking");
    } else {
        cout << (ns == 0 ? "Whiteking" : "Blackking");
    }
}
