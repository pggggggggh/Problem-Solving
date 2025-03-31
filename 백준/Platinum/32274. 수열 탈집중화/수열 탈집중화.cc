#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> mnpos, mxpos;
	int mx = 0, mn = 1e18;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 4);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		// a[i] = dis(gen);
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}
	// for (int i = 0; i < n; i++) cout << a[i] << ' ';
	// cout << '\n';
	if (mn == mx) {
		cout << "0\n";
		return;
	}
	int l = -1, r = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != mn && a[i] != mx) {
			if (l == -1) l = i;
			r = i;
		}
		if (a[i] == mn) mnpos.push_back(i);
		if (a[i] == mx) mxpos.push_back(i);
	}

	// mn, mx만 있다면
	if (mnpos.size() + mxpos.size() == n) {
		if (n % 2 == 0 && mnpos.size() == n / 2) {
			cout << "0\n";
			return;
		}
		if (n % 2 == 1 && (mnpos.size() == n / 2 + 1 || mnpos.size() == n / 2)) {
			cout << "0\n";
			return;
		}

		if (mnpos.size() < mxpos.size()) {
			int mns = mnpos.size();
			int l = mnpos[0], r = mnpos[0];
			while (mns < (n + 1) / 2) {
				if (l != 0 && a[l - 1] == mx) {
					l--;
					mns++;
				} else if (r != n - 1 && a[r + 1] == mx) {
					r++;
					mns++;
				} else if (l != 0 && a[l - 1] == mn) l--;
				else if (r != n - 1 && a[r + 1] == mn) r++;
			}
			cout << 1 << '\n';
			cout << 1 << ' ' << l + 1 << ' ' << r + 1 << '\n';
			return;
		} else {
			int mxs = mxpos.size();
			int l = mxpos[0], r = mxpos[0];
			while (mxs < (n + 1) / 2) {
				if (l != 0 && a[l - 1] == mn) {
					l--;
					mxs++;
				} else if (r != n - 1 && a[r + 1] == mn) {
					r++;
					mxs++;
				} else if (l != 0 && a[l - 1] == mx) l--;
				else if (r != n - 1 && a[r + 1] == mx) r++;
			}
			cout << 1 << '\n';
			cout << 2 << ' ' << l + 1 << ' ' << r + 1 << '\n';
			return;
		}
	}

	// mn으로 채우기
	int tmp_l = l, tmp_r = r;
	auto it = lower_bound(all(mnpos), l);
	if (it != mnpos.end() && *it <= r) {
	} else {
		int rcandi = 1e18, lcandi = -1e18;
		if (it != mnpos.end()) rcandi = *it;
		if (it != mnpos.begin()) lcandi = *(prev(it));

		if (rcandi - r < l - lcandi) r = rcandi;
		else l = lcandi;
	}
	int mns = 0;
	for (int i = 0; i < n; i++) {
		if (i >= l && i <= r) mns++;
		else if (a[i] == mn) mns++;
	}
	if (mns <= (n + 1) / 2) {
		while (mns < (n + 1) / 2) {
			if (l != 0 && a[l - 1] == mx) {
				l--;
				mns++;
			} else if (r != n - 1 && a[r + 1] == mx) {
				r++;
				mns++;
			} else if (l != 0 && a[l - 1] == mn) l--;
			else if (r != n - 1 && a[r + 1] == mn) r++;
		}
		cout << 1 << '\n';
		cout << 1 << ' ' << l + 1 << ' ' << r + 1 << '\n';
		return;
	}

	// mx로 채우기
	l = tmp_l, r = tmp_r;
	it = lower_bound(all(mxpos), l);
	if (it != mxpos.end() && *it <= r) {
	} else {
		int rcandi = 1e18, lcandi = -1e18;
		if (it != mxpos.end()) rcandi = *it;
		if (it != mxpos.begin()) lcandi = *(prev(it));

		if (rcandi - r < l - lcandi) r = rcandi;
		else l = lcandi;
	}
	int mxs = 0;
	for (int i = 0; i < n; i++) {
		if (i >= l && i <= r) mxs++;
		else if (a[i] == mx) mxs++;
	}
	if (mxs <= (n + 1) / 2) {
		while (mxs < (n + 1) / 2) {
			if (l != 0 && a[l - 1] == mn) {
				l--;
				mxs++;
			} else if (r != n - 1 && a[r + 1] == mn) {
				r++;
				mxs++;
			} else if (l != 0 && a[l - 1] == mx) l--;
			else if (r != n - 1 && a[r + 1] == mx) r++;
		}
		cout << 1 << '\n';
		cout << 2 << ' ' << l + 1 << ' ' << r + 1 << '\n';
		return;
	}

	// 두 번의 연산으로
	for (auto& x : mnpos) {
		if (x >= n / 2 - 1 && mxpos.back() > x) {
			cout << 2 << '\n';
			cout << "1 " << 1 << ' ' << x + 1 << '\n';
			cout << "2 " << n / 2 + 1 << ' ' << n << '\n';
			return;
		}
		if (x <= (n + 1) / 2 && mxpos[0] < x) {
			cout << 2 << '\n';
			cout << "1 " << x + 1 << ' ' << n << '\n';
			cout << "2 " << 1 << ' ' << (n + 1) / 2 << '\n';
			return;
		}
	}
	for (auto& x : mxpos) {
		if (x >= n / 2 - 1 && mnpos.back() > x) {
			cout << 2 << '\n';
			cout << "2 " << 1 << ' ' << x + 1 << '\n';
			cout << "1 " << n / 2 + 1 << ' ' << n << '\n';
			return;
		}
		if (x <= (n + 1) / 2 && mnpos[0] < x) {
			cout << 2 << '\n';
			cout << "2 " << x + 1 << ' ' << n << '\n';
			cout << "1 " << 1 << ' ' << (n + 1) / 2 << '\n';
			return;
		}
	}

	if (mnpos[0] <= (n + 1) / 2 && mxpos.back() > (n + 1) / 2) {
		cout << 2 << '\n';
		cout << "1 " << 1 << ' ' << (n + 1) / 2 << '\n';
		cout << "2 " << (n + 1) / 2 + 1 << ' ' << n << '\n';
		return;
	}
	if (mxpos[0] <= (n + 1) / 2 && mnpos.back() > (n + 1) / 2) {
		cout << 2 << '\n';
		cout << "2 " << 1 << ' ' << (n + 1) / 2 << '\n';
		cout << "1 " << (n + 1) / 2 + 1 << ' ' << n << '\n';
		return;
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << '\n';
		solve();
	}
}