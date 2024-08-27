#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define int long long
#define endl '\n'
using namespace std;
using pi = array<int, 2>;

int n, m;
vector<array<int, 3> > a;

bool comp(const array<int, 3> &a, const array<int, 3> &b) {
    if (a[0] == b[0]) return a[1] > b[1];
    return a[0] < b[0];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    a.resize(2 * m);
    for (int i = 0; i < m; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
        if (a[i][0] > a[i][1]) a[i][1] += n;
        a[i + m] = {a[i][0] + n, a[i][1] + n, i};
    }
    sort(all(a), comp);
    set<int> ans;
    for (int i = 0; i < m; i++) ans.insert(i);
    int mx = -1;
    for (int i = 0; i < 2 * m; i++) {
        if (a[i][1] <= mx) {
            ans.erase(a[i][2]);
        } else {
            mx = a[i][1];
        }
    }
    for (auto &x: ans) cout << x + 1 << " ";
}
