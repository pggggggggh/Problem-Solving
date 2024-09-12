#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int,int>;

struct node {
  node *l = 0;
  node *r = 0;
  node *p = 0;
  bool rev = false;

  void push() {
    if (rev) {
      rev = false;
      swap(l, r);
      if (l) l->rev ^= true;
      if (r) r->rev ^= true;
    }
  }

  bool is_root() {
    return p == 0 || (p->l != this && this != p->r);
  }
};

struct lct {
  vector<node> a;

  lct(int n) {
    a.resize(n);
  }

  void rot(node *c) {
    auto p = c->p;
    auto g = p->p;

    if (!p->is_root())
      (g->r == p ? g->r : g->l) = c;

    p->push();
    c->push();

    if (p->l == c) { // rtr
      p->l = c->r;
      c->r = p;
      if (p->l) p->l->p = p;
    } else { // rtl
      p->r = c->l;
      c->l = p;
      if (p->r) p->r->p = p;
    }

    p->p = c;
    c->p = g;
  }

  void splay(node *c) {
    while (!c->is_root()) {
      auto p = c->p;
      auto g = p->p;
      if (!p->is_root())
        rot((g->r == p) == (p->r == c) ? p : c);
      rot(c);
    }
    c->push();
  }

  node *access(int v) {
    node *last = 0;
    node *c = &a[v];
    for (node *p = c; p; p = p->p) {
      splay(p);
      p->r = last;
      last = p;
    }
    splay(c);
    return last;
  }

  void make_root(int v) {
    access(v);
    auto *c = &a[v];
    if (c->l)
      c->l->rev ^= true, c->l = 0;
  }

  void link(int u, int v) {
    make_root(v);
    node *c = &a[v];
    c->p = &a[u];
  }

  void cut(int u, int v) {
    make_root(u);
    access(v);
    if (a[v].l) {
      a[v].l->p = 0;
      a[v].l = 0;
    }
  }

  bool connected(int u, int v) {
    access(u);
    access(v);
    return a[u].p;
  }
};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  lct tree(n + 1);
  while (m--) {
    int w, x, y;
    cin >> w >> x >> y;
    if (w == 1) tree.link(x, y);
    else if (w == 2) tree.cut(x, y);
    else cout << tree.connected(x, y) << '\n';
  }
}
