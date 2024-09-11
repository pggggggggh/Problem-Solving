#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int,int>;

int cnt[1000005];

signed main() {
    int n;
    cin >> n;
    vector<pi> a(n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
        cnt[a[i].first]++;
    }
    for (int i = 0; i < n; i++) {
        int res = 0;
        for (int j = 1; j <= sqrt(a[i].first); j++) {
            if (a[i].first % j != 0) continue;
            res += cnt[j];
            if (a[i].first / j != j) res += cnt[a[i].first / j];
        }
        cout << res - 1 << '\n';
    }
}
