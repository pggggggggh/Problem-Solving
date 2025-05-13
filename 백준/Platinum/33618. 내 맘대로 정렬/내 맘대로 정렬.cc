#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

const int MOD = 1e9 + 7;

template <int MOD>
struct ModInt {
	int value;
	static const int MOD_value = MOD;

	ModInt(long long v = 0)
	{
		value = v % MOD;
		if (value < 0) value += MOD;
	}
	ModInt(long long a, long long b)
	    : value(0)
	{
		*this += a;
		*this /= b;
	}

	ModInt& operator+=(ModInt const& b)
	{
		value += b.value;
		if (value >= MOD) value -= MOD;
		return *this;
	}
	ModInt& operator-=(ModInt const& b)
	{
		value -= b.value;
		if (value < 0) value += MOD;
		return *this;
	}
	ModInt& operator*=(ModInt const& b)
	{
		value = (long long)value * b.value % MOD;
		return *this;
	}

	// mint::mexp
	static ModInt mexp(ModInt a, long long e)
	{
		ModInt res = 1;
		while (e) {
			if (e & 1) res *= a;
			a *= a;
			e >>= 1;
		}
		return res;
	}
	friend ModInt inverse(ModInt a) { return mexp(a, MOD - 2); }
	ModInt& operator/=(ModInt const& b) { return *this *= inverse(b); }
	friend ModInt operator+(ModInt a, ModInt const b) { return a += b; }
	friend ModInt operator-(ModInt a, ModInt const b) { return a -= b; }
	friend ModInt operator-(ModInt const a) { return 0 - a; }
	friend ModInt operator*(ModInt a, ModInt const b) { return a *= b; }
	friend ModInt operator/(ModInt a, ModInt const b) { return a /= b; }
	friend std::ostream& operator<<(std::ostream& os, ModInt const& a) { return os << a.value; }
	friend bool operator==(ModInt const& a, ModInt const& b) { return a.value == b.value; }
	friend bool operator!=(ModInt const& a, ModInt const& b) { return a.value != b.value; }
};

using mint = ModInt<MOD>;

mint fact[500005];

void solve()
{
	int n, q;
	map<int, int> adj;
	map<int, int> vis;
	cin >> n >> q;
	vector<pi> a(q);
	for (int i = 0; i < q; i++) {
		cin >> a[i].first >> a[i].second;
		adj[a[i].first] = a[i].second + 1;
		vis[a[i].first] = 0;
		vis[a[i].second + 1] = 0;
	}
	sort(all(a));
	for (int i = 1; i < q; i++) {
		if (a[i - 1].second >= a[i].first) {
			cout << "0\n";
			return;
		}
	}
	mint ans = fact[n];
	for (auto& [x, y] : vis) {
		if (y) continue;
		int cur = x;

		while (1) {
			vis[cur] = 1;
			if (adj.find(cur) == adj.end()) {
				if (cur <= n) {
					ans /= cur;
					// cout << cur << "!\n";
				}
				break;
			}
			// cout << adj[cur] - 1 << "!\n";
			ans /= (adj[cur] - 1);
			cur = adj[cur];
		}
	}
	cout << ans << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fact[0] = 1;
	for (int i = 1; i <= 500000; i++) {
		fact[i] = fact[i - 1] * i;
	}

	int t;
	cin >> t;
	while (t--) solve();
}