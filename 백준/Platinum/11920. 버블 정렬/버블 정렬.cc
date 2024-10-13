#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

struct dynamic_segtree {
	using S = int;
	static const S e = 0;

	S op(S a, S b)
	{
		return a + b;
	}

	struct Node {
		Node *l, *r;
		S val; // value of node
		Node()
		    : l(NULL)
		    , r(NULL)
		    , val(e)
		{
		}
	};

	Node* root;
	int max_r;

	dynamic_segtree(int max_r)
	    : max_r(max_r)
	{
		root = new Node();
	}

	void put(int x, int val, Node* node, int l, int r)
	{
		if (l == r) {
			node->val = val;
			return;
		}
		int mid = l + r >> 1;
		if (x <= mid) {
			if (!node->l) node->l = new Node();
			put(x, val, node->l, l, mid);
		} else {
			if (!node->r) node->r = new Node();
			put(x, val, node->r, mid + 1, r);
		}
		S lval = node->l ? node->l->val : e;
		S rval = node->r ? node->r->val : e;
		node->val = op(lval, rval);
	}

	void put(int x, int val)
	{
		put(x, val, root, 0, max_r);
	}

	void add(int x, int val, Node* node, int l, int r)
	{
		if (l == r) {
			node->val = op(node->val, val);
			return;
		}
		int mid = l + r >> 1;
		if (x <= mid) {
			if (!node->l) node->l = new Node();
			add(x, val, node->l, l, mid);
		} else {
			if (!node->r) node->r = new Node();
			add(x, val, node->r, mid + 1, r);
		}
		S lval = node->l ? node->l->val : e;
		S rval = node->r ? node->r->val : e;
		node->val = op(lval, rval);
	}

	void add(int x, int val)
	{
		add(x, val, root, 0, max_r);
	}

	S query(int x, int y, Node* node, int l, int r)
	{
		if (!node) return e;
		if (r < x || y < l) return e;
		if (x <= l && r <= y) return node->val;
		int mid = l + r >> 1;
		return op(query(x, y, node->l, l, mid), query(x, y, node->r, mid + 1, r));
	}

	S query(int x, int y)
	{
		return query(x, y, root, 0, max_r);
	}

	// only applicable in int/sum segtree
	int kth_element(int k)
	{
		if (root->val < k) return -1;
		Node* node = root;
		int l = 0, r = max_r;
		while (l != r) {
			int mid = l + r >> 1;
			S lval = node->l ? node->l->val : e;
			if (lval < k) {
				k -= lval;
				node = node->r;
				l = mid + 1;
			} else {
				node = node->l;
				r = mid;
			}
		}
		return l;
	}
};

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	dynamic_segtree seg(1e9 + 5);
	vector<int> sorted, res(n, -1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		seg.add(a[i], 1);
		int delta = seg.query(a[i] + 1, 1e9);
		if (delta >= k) res[i - k] = a[i];
		else sorted.push_back(a[i]);
	}
	sort(all(sorted));
	int ptr = 0;
	for (int i = 0; i < n; i++) {
		if (res[i] == -1) cout << sorted[ptr++] << ' ';
		else cout << res[i] << ' ';
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}