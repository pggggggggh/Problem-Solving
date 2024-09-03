#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()

struct lazyseg {
    using S = int;

    using L = int;

    static constexpr S seg_e = 0; // identity of seg_op

    static constexpr L lazy_e = 0; // identity of lazy_op

    static S seg_op(S a, S b) { // combine two nodes
        return a + b;
    }

    static L lazy_op(L a, L b) { // combine two lazy values
        return a + b;
    }

    static void apply_lazy(S &s, L l, int len) {
        s += l * len;
    }

    int n, sz;
    vector<S> seg;
    vector<L> lazy;

    lazyseg(int n, const vector<S> &v = vector<S>()) {
        assert(n >= v.size());
        this->n = n;
        sz = 1;
        while (sz < n) sz *= 2;
        seg = vector(2 * sz, seg_e);
        lazy = vector(2 * sz, lazy_e);
        for (int i = 0; i < v.size(); i++) seg[i + sz] = v[i];
        for (int i = sz - 1; i >= 1; i--) seg[i] = seg_op(seg[i * 2], seg[i * 2 + 1]);
    }

    void propa(int node, int l, int r) {
        if (lazy[node] == lazy_e) return;
        apply_lazy(seg[node], lazy[node], r - l + 1);
        if (l != r) {
            lazy[node * 2] = lazy_op(lazy[node * 2], lazy[node]);
            lazy[node * 2 + 1] = lazy_op(lazy[node * 2 + 1], lazy[node]);
        }
        lazy[node] = lazy_e;
    }

    void put(int x, S val, int node, int l, int r) {
        propa(node, l, r);
        if (l == r) {
            seg[node] = val;
            return;
        }
        int mid = l + r >> 1;
        if (x <= mid) put(x, val, node * 2, l, mid);
        else put(x, val, node * 2 + 1, mid + 1, r);
        seg[node] = seg_op(seg[node * 2], seg[node * 2 + 1]);
    }

    void put(int x, S val) {
        put(x, val, 1, 0, sz - 1);
    }

    void add(int x, int y, S val, int node, int l, int r) {
        propa(node, l, r);
        if (r < x || y < l) return;
        if (x <= l && r <= y) {
            lazy[node] = lazy_op(lazy[node], val);
            propa(node, l, r);
            return;
        }
        int mid = l + r >> 1;
        add(x, y, val, node * 2, l, mid);
        add(x, y, val, node * 2 + 1, mid + 1, r);
        seg[node] = seg_op(seg[node * 2], seg[node * 2 + 1]);
    }

    void add(int x, int y, S val) {
        add(x, y, val, 1, 0, sz - 1);
    }

    S query(int x, int y, int node, int l, int r) {
        propa(node, l, r);
        if (r < x || y < l) return seg_e;
        if (x <= l && r <= y) return seg[node];
        int mid = l + r >> 1;
        return seg_op(query(x, y, node * 2, l, mid), query(x, y, node * 2 + 1, mid + 1, r));
    }

    S query(int x, int y) {
        return query(x, y, 1, 0, sz - 1);
    }
};

// when edge query :
// if (hld.depth[u] < hld.depth[v]) swap(u, v); hld.update(u, w);
// if you want to use custom root(ex:1) call constructor(adj,1)

struct heavy_light_decomposition {
    int n;
    vector<vector<int> > adj, g; // adj must be bidirectional
    vector<int> par, depth, sz, top, pos, vis;
    int dfn = 0;
    lazyseg seg;

    heavy_light_decomposition(const vector<vector<int> > &_adj, int root = 0)
        : n(_adj.size()), adj(_adj), g(n),
          par(n), depth(n), sz(n), top(n), pos(n), vis(n), seg(n) {
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
        pos[v] = dfn++; // 0-indexed
        for (auto &u: g[v]) {
            top[u] = u == g[v][0] ? top[v] : u;
            dfs_hld(u);
        }
    }

    void update(int v, int w) { // vertex
        seg.put(pos[v], w);
    }

    int query(int a, int b) {
        int res = seg.seg_e;
        while (top[a] != top[b]) {
            if (depth[top[a]] < depth[top[b]]) swap(a, b);
            int st = top[a];
            res = seg.seg_op(res, seg.query(pos[st], pos[a]));
            a = par[st];
        }
        if (depth[a] > depth[b]) swap(a, b);
        res = seg.seg_op(res, seg.query(pos[a] + 1, pos[b]));
        // pos[a] if vertex query, pos[a]+1 if edge query!!!!!
        return res;
    }

    void add(int a, int b, int w) {
        while (top[a] != top[b]) {
            if (depth[top[a]] < depth[top[b]]) swap(a, b);
            int st = top[a];
            seg.add(pos[st], pos[a], w);
            a = par[st];
        }
        if (depth[a] > depth[b]) swap(a, b);
        seg.add(pos[a] + 1, pos[b], w);
        // pos[a] if vertex query, pos[a]+1 if edge query!!!!!
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > adj(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    heavy_light_decomposition hld(adj);
    while (m--) {
        char w;
        int x, y;
        cin >> w >> x >> y;
        x--, y--;
        if (w == 'P') {
            hld.add(x, y, 1);
        } else {
            cout << hld.query(x, y) << '\n';
        }
    }
}
