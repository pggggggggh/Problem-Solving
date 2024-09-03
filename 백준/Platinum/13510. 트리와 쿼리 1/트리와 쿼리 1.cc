#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()

struct segtree {
    using S = int;

    static constexpr S e = 0;

    static S op(S a, S b) {
        return max(a, b);
    }

    int n, sz;
    vector<S> seg;

    segtree(int n, const vector<S> &v = vector<S>()) {
        assert(n >= v.size());
        this->n = n;
        sz = 1;
        while (sz < n) sz *= 2;
        seg = vector(2 * sz, e);
        for (int i = 0; i < v.size(); i++) seg[i + sz] = v[i];
        for (int i = sz - 1; i >= 1; i--) seg[i] = op(seg[i * 2], seg[i * 2 + 1]);
    }

    void put(int x, const S &val) {
        x += sz;
        seg[x] = val;
        while (x > 1) {
            x /= 2;
            seg[x] = op(seg[x * 2], seg[x * 2 + 1]);
        }
    }

    // void update(int x, const S &val) {
    //     x += sz;
    //     seg[x] = op(seg[x], val);
    //
    //     while (x > 1) {
    //         x /= 2;
    //         seg[x] = op(seg[x * 2], seg[x * 2 + 1]);
    //     }
    // }

    S query(int l, int r) {
        S res = e;
        l += sz, r += sz;
        for (; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) res = op(res, seg[l++]);
            if (!(r & 1)) res = op(res, seg[r--]);
        }
        return res;
    }
};

struct heavy_light_decomposition {
    int n;
    vector<vector<int> > adj, g; // adj : bidirectional, g : only tree edges
    vector<int> par, depth, sz, top, pos, vis;
    int dfn = 0;
    segtree seg;

    heavy_light_decomposition(const vector<vector<int> > &_adj, int root = 0)
        : n(_adj.size()), adj(_adj), g(n),
          par(n), depth(n), sz(n), top(n), pos(n), vis(n), seg(n) {
        top[root] = root;
        par[root] = -1;
        dfs_tree(root);
        dfs_size(root);
        dfs_hld(root);
    }

    void dfs_tree(int v) {
        vis[v] = 1;
        for (auto &u: adj[v]) {
            if (vis[u]) continue;
            g[v].push_back(u);
            dfs_tree(u);
        }
    }

    void dfs_size(int v) {
        sz[v] = 1;
        for (auto &u: g[v]) {
            depth[u] = depth[v] + 1;
            par[u] = v;
            dfs_size(u);
            sz[v] += sz[u];
            if (sz[u] > sz[g[v][0]]) swap(u, g[v][0]);
        }
    }

    void dfs_hld(int v) {
        pos[v] = dfn++; // 0~
        for (auto &u: g[v]) {
            top[u] = u == g[v][0] ? top[v] : u;
            dfs_hld(u);
        }
    }

    void update(int v, int w) { // vertex
        seg.put(pos[v], w);
    }

    int query(int a, int b) {
        int res = 0;
        while (top[a] != top[b]) {
            if (depth[top[a]] < depth[top[b]]) swap(a, b);
            int st = top[a];
            res = max(res, seg.query(pos[st], pos[a]));
            a = par[st];
        }
        if (depth[a] > depth[b]) swap(a, b);
        res = max(res, seg.query(pos[a] + 1, pos[b]));
        return res;
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n;
    vector<vector<int> > adj(n);
    vector<array<int, 3> > edges;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v, w});
    }
    heavy_light_decomposition hld(adj);
    for (auto &[u,v,w]: edges) {
        if (hld.depth[u] > hld.depth[v]) hld.update(u, w);
        else hld.update(v, w);
    }
    cin >> q;
    while (q--) {
        int w, x, y;
        cin >> w >> x >> y;
        if (w == 1) {
            x--;
            auto [u,v,w] = edges[x];
            if (hld.depth[u] > hld.depth[v]) hld.update(u, y);
            else hld.update(v, y);
            // for (int i = 0; i < n; i++) {
            //     cout << i << ':' << hld.seg.query(i, i) << '\n';
            // }
        } else {
            x--, y--;
            if (x == y) cout << 0 << '\n';
            else cout << hld.query(x, y) << '\n';
        }
    }
}
