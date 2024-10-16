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
	int n, m;
	cin >> n >> m;
	vector dp(n + 1, vector<mint>(n * m + 5));
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= (i - 1) * m + 1; j++) {
			dp[i][j] += dp[i][j - 1];
			dp[i][j] += dp[i - 1][j - 1];
		}
	}
	mint res = 0;
	for (int i = 1; i <= n * m; i++) res += dp[n][i];
	for (int i = 1; i <= n; i++) res *= i;
	cout << res;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}