#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int,int>;

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > adj(n);
    vector<int> indegree(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        indegree[y]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (!indegree[i]) q.push(i);
    }
    vector<int> res;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        res.push_back(v);
        for (auto &u: adj[v]) {
            indegree[u]--;
            if (!indegree[u]) q.push(u);
        }
    }
    for (auto &x: res) cout << x + 1 << ' ';
}
