#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

struct splaytree {
	struct node {
		node *l, *r, *p;
		int siz, sum, val;

		node(int val)
		    : l(NULL), r(NULL), p(NULL), siz(1), val(val), sum(val) { }

		node(int val, node* p)
		    : l(NULL), r(NULL), p(p), siz(1), val(val), sum(val) { }
	};

	node* root;
	vector<node*> ptr;

	splaytree(vector<int>& a)
	    : root(NULL)
	{
		root = new node(-1e18);
		node* x = root;
		ptr.resize(a.size() + 2);
		for (int i = 1; i <= a.size(); i++) {
			ptr[i] = x->r = new node(a[i], x);
			x = x->r;
		}
		x->r = new node(1e18, x);
		for (int i = a.size(); i >= 1; i--) update(ptr[i]);
		splay(ptr[a.size() / 2]);
	}

	void rotate(node* x)
	{
		node* p = x->p;
		node* b;
		if (x == p->l) {
			p->l = b = x->r;
			x->r = p;
		} else {
			p->r = b = x->l;
			x->l = p;
		}
		x->p = p->p;
		p->p = x;
		if (b) b->p = p;
		if (!x->p) root = x;
		else {
			if (p == x->p->l) x->p->l = x;
			else x->p->r = x;
		}
		update(p);
		update(x);
	}

	void splay(node* x, node* g = NULL)
	{
		while (x->p != g) {
			node* p = x->p;
			if (p->p == g) {
				rotate(x);
				break;
			}
			auto pp = p->p;
			if ((p->l == x) == (pp->l == p)) {
				rotate(p);
				rotate(x);
			} else {
				rotate(x);
				rotate(x);
			}
		}
		if (!g) root = x;
	}

	void update(node* x)
	{
		x->siz = 1;
		x->sum = x->val;
		if (x->l) {
			x->siz += x->l->siz;
			x->sum += x->l->sum;
		}
		if (x->r) {
			x->siz += x->r->siz;
			x->sum += x->r->sum;
		}
	}

	void kth(int k)
	{
		node* x = root;
		while (1) {
			while (x->l && x->l->siz > k) x = x->l;
			if (x->l) k -= x->l->siz;
			if (!k--) break;
			x = x->r;
		}
		splay(x);
	}

	node* gather(int s, int e)
	{
		kth(e + 1);
		auto tmp = root;
		kth(s - 1);
		splay(tmp, root);
		return root->r->l;
	}
};

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	splaytree spt(a);
	int q = m + k;
	while (q--) {
		int x, y, z;
		cin >> x >> y >> z;
		if (x == 1) {
			spt.kth(y);
			spt.root->val = z;
			spt.update(spt.root);
		} else {
			cout << spt.gather(y, z)->sum << '\n';
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}