#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = array<int, 2>;

struct edge {
    int from, to, cost;
};

void solve() {
    int n, m, w;
    cin >> n >> m >> w;
    vector<edge> E;
    for (int i = 0; i < m + w; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        if (i >= m) c *= -1;
        else E.push_back({b, a, c}); // roads are undirected
        E.push_back({a, b, c});
    }
    auto bellman = [&]() -> int {
        vector<int> dist(n, 1e9);
        for (int t = 0; t < n; t++) {
            bool updated = false;
            for (auto &e: E) {
                if (dist[e.from] + e.cost < dist[e.to]) {
                    if (t == n - 1) return 1;
                    dist[e.to] = dist[e.from] + e.cost;
                    updated = true;
                }
            }
            if (!updated) return 0;
        }
        return 0;
    };
    int ans = 0;
    cout << (bellman() ? "YES" : "NO") << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
