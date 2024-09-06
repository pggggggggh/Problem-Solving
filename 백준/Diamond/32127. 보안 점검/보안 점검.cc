#include <bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
using pi = pair<int, int>;

int n, m, d, q;
int a[100005];
int max_l;
int par[2005][20005];
int sum[2005][20005];
vector<array<int, 3> > E;
vector<array<int, 4> > Q;
vector<int> l_sorted;

int find(int x, int l) {
    if (par[x][l] == x) return x;
    return par[x][l] = find(par[x][l], l);
}

void uni(int x, int y, int l) { // y를 x에
    x = find(x, l);
    y = find(y, l);
    if (x == y) return;
    par[y][l] = x;
    sum[x][l] += sum[y][l];
}

void debug() {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= max_l; j++) {
            cout << "below" << j << ' ' << i << ':' << find(i, j) <<
                    '(' << sum[find(i, j)][j] << ")\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> d;
    if (n > 2000 || m > 4000) return 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    E.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> E[i][0] >> E[i][1] >> E[i][2];
        l_sorted.push_back(E[i][2]);
    }
    cin >> q;
    if (q > 4000) return 0;
    for (int i = 0; i < q; i++) {
        int w, x = 0, y = 0, z = 0;
        cin >> w;
        if (w == 1) {
            cin >> x >> y >> z;
            l_sorted.push_back(z);
        } else if (w == 2) cin >> x >> y;
        else if (w == 3) cin >> x;
        Q.push_back({w, x, y, z});
    }
    l_sorted.push_back(0);
    sort(all(l_sorted));
    l_sorted.erase(unique(all(l_sorted)), l_sorted.end());
    max_l = l_sorted.size(); // 추가할 때 l~max_l까지
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= max_l; j++) {
            par[i][j] = i;
            sum[i][j] = a[i];
        }
    }
    for (auto &[s,e,x]: E) {
        x = lower_bound(all(l_sorted), x) - l_sorted.begin();
        for (int i = x; i <= max_l; i++) {
            uni(s, e, i);
        }
    }

    for (int i = 0; i < q; i++) {
        if (Q[i][0] != 1) continue;
        Q[i][3] = lower_bound(all(l_sorted), Q[i][3]) - l_sorted.begin();
    }

    for (int i = 0; i < q; i++) {
        if (Q[i][0] == 1) {
            for (int j = Q[i][3]; j <= max_l; j++) {
                uni(Q[i][1], Q[i][2], j);
            }
        } else if (Q[i][0] == 2) {
            int add = Q[i][2] - a[Q[i][1]];
            for (int j = 0; j <= max_l; j++) {
                sum[find(Q[i][1], j)][j] += add;
            }
            a[Q[i][1]] += add;
        } else if (Q[i][0] == 3) d = Q[i][1];
        else {
            int lo = -1, hi = max_l + 1;
            while (lo + 1 < hi) {
                int mid = lo + hi >> 1;
                int flag = 0;
                for (int i = 1; i <= n; i++) {
                    if (sum[find(i, mid)][mid] >= d) {
                        flag = 1;
                        break;
                    }
                }
                if (flag) hi = mid;
                else lo = mid;
            }
            if (hi == 0) cout << -1 << '\n';
            else if (hi == max_l + 1) cout << -2 << '\n';
            else cout << l_sorted[hi] << '\n';
        }
    }
}
