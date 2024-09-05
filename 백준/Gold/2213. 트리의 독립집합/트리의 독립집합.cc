#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define MOD 1000001
using pi = pair<int, int>;

int n;
int a[10005];
vector<int> g[10005];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int> > adj(n + 1);
    for (int i = 2; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> order;
    function<void(int,int)> dfs = [&](int v,int p) {
        order.push_back(v);
        for (auto &u: adj[v]) {
            if (u == p) continue;
            g[v].push_back(u);
            dfs(u, v);
        }
    };
    dfs(1, -1);
    reverse(all(order));
    vector<array<int, 2> > dp(n + 1);
    vector<array<int, 2> > chk(n + 1);
    // dp[v][i] = v의 부모 u가 dp[u][i] 만들 때 v를 1로 선택했나?
    for (auto &v: order) {
        dp[v][0] = 0;
        dp[v][1] = a[v];
        for (auto &u: g[v]) {
            if (dp[u][0] > dp[u][1]) chk[u][0] = 0;
            else chk[u][0] = 1;
            dp[v][0] += max(dp[u][0], dp[u][1]);
            chk[u][1] = 0;
            dp[v][1] += dp[u][0];
        }
    }
    vector<int> res;
    cout << max(dp[1][0], dp[1][1]) << '\n';
    function<void(int,int)> dfs2 = [&](int v, int cur) {
        for (auto &u: g[v]) {
            if (chk[u][cur]) {
                res.push_back(u);
                dfs2(u, 1);
            } else dfs2(u, 0);
        }
    };
    if (dp[1][0] < dp[1][1]) {
        res.push_back(1);
        dfs2(1, 1);
    } else dfs2(1, 0);
    sort(all(res));
    for (auto &x: res) cout << x << ' ';
}
