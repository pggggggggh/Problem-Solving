#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

template <int MOD>
struct ModInt {
	int r;
	static ModInt Pow(ModInt x, size_t n)
	{
		ModInt ret = 1;
		for (; n; n >>= 1, x *= x)
			if (n & 1) ret *= x;
		return ret;
	}
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

using mint = ModInt<1'000'000'000>;

void solve()
{
	int n;
	cin >> n;
	vector<mint> dp(n + 1);
	dp[2] = 1;
	for (int i = 3; i <= n; i++) dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
	cout << dp[n];
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}