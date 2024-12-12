#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

struct splaytree {
	struct node {
		node *l, *r, *p;
		int siz, val, sum, mx, mn;
		bool flip;

		node(int x)
		{
			l = r = p = NULL;
			siz = 1;
			val = sum = mx = mn = x;
			flip = false;
		}

		node(int x, node* p)
		    : node(x)
		{
			this->p = p;
		}
	};

	node* root;
	vector<node*> ptr;

	splaytree(vector<int>& a)
	{
		root = new node(-1e18);
		node* x = root;
		ptr.resize(a.size() + 1);
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
		push(p);
		push(x);
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
		x->sum = x->mx = x->mn = x->val;
		if (x->l) {
			x->siz += x->l->siz;
			x->sum += x->l->sum;
			x->mx = max(x->mx, x->l->mx);
			x->mn = min(x->mn, x->l->mn);
		}
		if (x->r) {
			x->siz += x->r->siz;
			x->sum += x->r->sum;
			x->mx = max(x->mx, x->r->mx);
			x->mn = min(x->mn, x->r->mn);
		}
	}

	void push(node* x)
	{
		if (!x->flip) return;
		swap(x->l, x->r);
		if (x->l) x->l->flip ^= 1;
		if (x->r) x->r->flip ^= 1;
		x->flip = false;
	}

	node* kth(int k)
	{
		node* x = root;
		push(x);
		while (1) {
			while (x->l && x->l->siz > k) {
				x = x->l;
				push(x);
			}
			if (x->l) k -= x->l->siz;
			if (!k--) break;
			x = x->r;
			push(x);
		}
		splay(x);
		return x;
	}

	node* gather(int s, int e)
	{
		kth(e + 1);
		auto tmp = root;
		kth(s - 1);
		splay(tmp, root);
		return root->r->l;
	}

	node* flip(int s, int e)
	{
		node* x = gather(s, e);
		x->flip ^= 1;
		return x;
	}

	void shift(int s, int e, int k)
	{
		k += (e - s + 1) * 5000000;
		k %= (e - s + 1);
		if (k == 0) return;
		flip(s, e);
		flip(s, s + k - 1);
		flip(s + k, e);
	}

	int idx(int x)
	{
		splay(ptr[x]);
		return root->l->siz;
	}
};

void solve()
{
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) a[i] = i;
	splaytree spt(a);
	while (q--) {
		int x, y, z, w;
		cin >> x;
		if (x == 1) {
			cin >> y >> z;
			auto p = spt.flip(y, z);
			cout << p->mn << ' ' << p->mx << ' ' << p->sum << '\n';
		} else if (x == 2) {
			cin >> y >> z >> w;
			spt.shift(y, z, w);
			auto p = spt.gather(y, z);
			cout << p->mn << ' ' << p->mx << ' ' << p->sum << '\n';
		} else if (x == 3) {
			cin >> y;
			cout << spt.kth(y)->val << '\n';
		} else if (x == 4) {
			cin >> y;
			cout << spt.idx(y) << '\n';
		}
	}
	for (int i = 1; i <= n; i++) cout << spt.kth(i)->val << ' ';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}