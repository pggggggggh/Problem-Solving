#include <bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
using pi = pair<int, int>;

struct persistent_segtree {
    using S = int;
    static const S e = 0;

    S op(S a, S b) {
        return a + b;
    }

    struct Node {
        Node *l, *r;
        S val; // value of node
        Node(): l(NULL), r(NULL), val(e) {
        }
    };

    vector<Node *> roots;
    int max_r;

    void construct(const vector<S> &v, Node *node, int l, int r) {
        if (l == r) {
            node->val = v[l];
            return;
        }
        int mid = l + r >> 1;
        node->l = new Node();
        node->r = new Node();
        construct(v, node->l, l, mid);
        construct(v, node->r, mid + 1, r);
        node->val = op(node->l->val, node->r->val);
    }

    persistent_segtree(int max_r): max_r(max_r) {
        roots.push_back(new Node()); // dummy node
    }

    persistent_segtree(int max_r, const vector<S> &v): max_r(max_r) {
        assert(max_r >= v.size());
        roots.push_back(new Node());
        construct(v, roots.back(), 0, max_r);
    }

    void put(int x, int val, Node *node, Node *prev, int l, int r) {
        if (l == r) {
            node->val = val;
            return;
        }
        int mid = l + r >> 1;
        if (x <= mid) { // create left, re-use prev's right
            node->l = new Node();
            node->r = prev->r;
            put(x, val, node->l, prev->l, l, mid);
        } else {
            node->r = new Node();
            node->l = prev->l;
            put(x, val, node->r, prev->r, mid + 1, r);
        }
        S lval = node->l ? node->l->val : e;
        S rval = node->r ? node->r->val : e;
        node->val = op(lval, rval);
    }

    void put(int x, int val) {
        Node *new_root = new Node();
        put(x, val, new_root, roots.back(), 0, max_r);
        roots.push_back(new_root);
    }

    S query(int x, int y, Node *node, int l, int r) {
        if (!node) return e;
        if (r < x || y < l) return e;
        if (x <= l && r <= y) return node->val;
        int mid = l + r >> 1;
        return op(query(x, y, node->l, l, mid), query(x, y, node->r, mid + 1, r));
    }

    S query(int x, int y) {
        return query(x, y, roots.back(), 0, max_r);
    }

    S query(int time, int x, int y) {
        assert(time < roots.size());
        return query(x, y, roots[time], 0, max_r);
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    persistent_segtree pst(n + 1, a);
    cin >> m;
    while (m--) {
        int w, x, y, z;
        cin >> w >> x >> y;
        if (w == 1) {
            pst.put(x, y);
        } else {
            cin >> z;
            cout << pst.query(x, y, z) << '\n';
        }
    }
}
