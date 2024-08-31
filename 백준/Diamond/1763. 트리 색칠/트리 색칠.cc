#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int,int>;

struct node {
    int cost, size, idx;

    bool operator<(const node &x) const {
        return cost * x.size < x.cost * size;
    }

    bool operator>(const node &x) const {
        return cost * x.size > x.cost * size;
    }
};

int uf[1005];

int find(int x) {
    if (uf[x] == x) return x;
    return uf[x] = find(uf[x]);
}

void uni(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    uf[y] = x;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, root;
    cin >> n >> root;
    root--;
    vector<node> a(n);
    vector<vector<int> > adj(n);
    // priority_queue<node, vector<node>, greater<node> > pq;
    for (int i = 0; i < n; i++) {
        cin >> a[i].cost;
        a[i].size = 1;
        a[i].idx = i;
        // pq.push(a[i]);
        uf[i] = i;
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> par(n);
    function<void(int,int)> dfs = [&](int u, int p) {
        for (auto &v: adj[u]) {
            if (v == p) continue;
            par[v] = u;
            dfs(v, u);
        }
    };
    dfs(root, -1);
    int res = 0;
    for (int i = 0; i < n - 1; i++) {
        int idx = -1;
        for (int j = 0; j < n; j++) {
            if (find(j) != j || j == root) continue;
            if (idx == -1 || a[j] > a[idx]) idx = j;
        }
        idx = find(idx);
        int p = find(par[idx]);
        res += a[idx].cost * a[p].size;
        a[p].cost += a[idx].cost;
        a[p].size += a[idx].size;
        uni(p, idx);
    }
    cout << res + a[root].cost << '\n';
}
