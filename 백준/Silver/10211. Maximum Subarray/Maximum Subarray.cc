#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int,int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    function<int(int,int)> recur = [&](int s, int t) {
        if (s == t) return a[s];
        int mid = s + t >> 1;
        int sol_left = recur(s, mid), sol_right = recur(mid + 1, t);
        int subsol_l = -1e18, subsol_r = -1e18;
        int sum_l = 0, sum_r = 0;
        for (int i = mid; i >= s; i--) {
            sum_l += a[i];
            subsol_l = max(subsol_l, sum_l);
        }
        for (int i = mid + 1; i <= t; i++) {
            sum_r += a[i];
            subsol_r = max(subsol_r, sum_r);
        }

        return max({sol_left, sol_right, subsol_l + subsol_r});
    };
    cout << recur(0, n - 1) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
