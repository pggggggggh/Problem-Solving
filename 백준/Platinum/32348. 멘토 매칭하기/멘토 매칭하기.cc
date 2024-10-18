#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

template <int MOD>
struct ModInt {
private:
	int r;
	static ModInt Pow(ModInt x, size_t n)
	{
		ModInt ret = 1;
		for (; n; n >>= 1, x *= x)
			if (n & 1) ret *= x;
		return ret;
	}

public:
	constexpr ModInt()
	    : r(0)
	{
	}
	constexpr ModInt(int x)
	    : r(x % MOD)
	{
		if (r < 0) r += MOD;
	}
	ModInt Inv() const
	{
		return Pow(*this, MOD - 2);
	}
	ModInt operator-() const
	{
		return r ? MOD - r : 0;
	}
	ModInt operator+(const ModInt& x) const
	{
		return ModInt(*this) += x;
	}
	ModInt operator-(const ModInt& x) const
	{
		return ModInt(*this) -= x;
	}
	ModInt operator*(const ModInt& x) const
	{
		return ModInt(*this) *= x;
	}
	ModInt operator/(const ModInt& x) const
	{
		return ModInt(*this) /= x;
	}
	ModInt operator+=(const ModInt& x)
	{
		r += x.r;
		if (r >= MOD) r -= MOD;
		return *this;
	}
	ModInt operator-=(const ModInt& x)
	{
		r -= x.r;
		if (r < 0) r += MOD;
		return *this;
	}
	ModInt operator*=(const ModInt& x)
	{
		r = (int)r * x.r % MOD;
		return *this;
	}
	ModInt operator/=(const ModInt& x)
	{
		return *this *= x.Inv();
	}
	bool operator==(const ModInt& x) const
	{
		return r == x.r;
	}
	bool operator!=(const ModInt& x) const
	{
		return r != x.r;
	}
	operator int() const
	{
		return r;
	}
	friend istream& operator>>(istream& in, ModInt& x)
	{
		int t;
		cin >> t;
		x = ModInt(t);
		return in;
	}
	friend ostream& operator<<(ostream& out, const ModInt& x)
	{
		return out << x.r;
	}
};

using mint = ModInt<1'000'000'007>;

void solve()
{
	vector<mint> fact(200005);
	fact[0] = 1;
	for (int i = 1; i <= 200000; i++) fact[i] = fact[i - 1] * mint(i);

	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	sort(all(a));
	sort(all(b));
	reverse(all(b));
	int ans = 1e18;
	for (int i = 0; i < n; i++) {
		if (i >= m) ans = min(ans, a[i]);
		else ans = min(ans, a[i] + b[i]);
	}
	reverse(all(b));
	int used = 0;
	int left = 0;
	mint res(1);
	for (int i = 0; i < n; i++) {
		if (a[i] >= ans) {
			left = n - i;
			break;
		}
		int idx = lower_bound(all(b), ans - a[i]) - b.begin();
		int need = m - idx;
		res *= mint(need - used);
		used++;
	}
	int unused = m - used;
	// left명에게 unused만큼 매칭하기
	mint match(0);
	for (int i = 0; i <= min(left, unused); i++) {
		mint c = fact[unused] / fact[unused - i] / fact[i];
		mint p = fact[left] / fact[left - i];
		match += c * p;
	}
	cout << res * match;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}