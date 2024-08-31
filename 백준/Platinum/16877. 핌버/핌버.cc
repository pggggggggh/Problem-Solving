#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int,int>;

signed main() {
    vector<int> fibo = {0, 1, 2};
    vector<int> g(3000005);
    for (int i = 3; fibo.back() < 3000000; i++) {
        fibo.push_back(fibo.back() + *next(fibo.rbegin()));
    }
    for (int i = 1; i <= 3000000; i++) {
        int idx = prev(upper_bound(all(fibo), i)) - fibo.begin();
        vector<int> cnt(idx + 1);
        for (int j = 1; j <= idx; j++) cnt[g[i - fibo[j]]] = 1;
        for (int j = 0; j <= idx; j++) {
            if (!cnt[j]) {
                g[i] = j;
                break;
            }
        }
    }
    int n;
    cin >> n;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cur ^= g[x];
    }
    if (cur) cout << "koosaga";
    else cout << "cubelover";
}
