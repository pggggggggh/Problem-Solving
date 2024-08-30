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
    priority_queue<int, vector<int>, greater<int> > q;
    for (int i = 0; i < n; i++) {
        if (!indegree[i]) q.push(i);
    }
    while (!q.empty()) {
        int v = q.top();
        q.pop();
        cout << v + 1 << ' ';
        for (auto &u: adj[v]) {
            indegree[u]--;
            if (!indegree[u]) q.push(u);
        }
    }
}
