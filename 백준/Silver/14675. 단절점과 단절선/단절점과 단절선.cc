#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int,int>;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n;
    vector<int> degree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        degree[x]++;
        degree[y]++;
    }
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (x == 2) cout << "yes\n";
        else cout << (degree[y] > 1 ? "yes\n" : "no\n");
    }
}
