#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

string s;
int n, k;
vector<vector<int>> g;
vector<int> close;
vector<set<string>> a;

int uu;
vector<string> cur;

void recur(int now)
{
	if (now == g[uu].size()) {
		string sex;
		sex.reserve(close[uu] - uu);
		int ptr = 0;
		for (int i = uu + 1; i < close[uu]; i++) {
			if (ptr < g[uu].size() && i == g[uu][ptr]) {
				sex += cur[ptr];
				i = close[g[uu][ptr]];
				ptr++;
			} else {
				sex += s[i];
			}
		}
		a[uu].insert(sex);
		return;
	}

	for (auto& s : a[g[uu][now]]) {
		cur.push_back(s);
		recur(now + 1);
		cur.pop_back();
		if (a[uu].size() > k) return;
	}
}

void recur2(int now)
{
	if (now == -1) {
		string sex;
		sex.reserve(close[uu] - uu);
		int ptr = 0;
		for (int i = uu + 1; i < close[uu]; i++) {
			if (ptr < g[uu].size() && i == g[uu][ptr]) {
				reverse(all(cur[cur.size() - 1 - ptr]));
				sex += cur[cur.size() - 1 - ptr];
				reverse(all(cur[cur.size() - 1 - ptr]));
				i = close[g[uu][ptr]];
				ptr++;
			} else {
				sex += s[i];
			}
		}
		reverse(all(sex));
		a[uu].insert(sex);
		return;
	}

	int togo = a[uu].size() + k;
	for (auto it = a[g[uu][now]].begin(); it != a[g[uu][now]].end(); it++) {
		cur.push_back(*it);
		recur2(now - 1);
		cur.pop_back();
		if (a[uu].size() > togo) return;
	}
}

void dfs(int u)
{
	for (auto& v : g[u]) {
		dfs(v);
	}
	uu = u;
	recur(0);
	recur2(g[uu].size() - 1);
	// cout << u << ':';
	// for (auto& s : a[u]) cout << s << ' ';
	// cout << '\n';
}

void solve()
{
	cin >> s >> k;
	n = s.size();
	g.resize(n);
	a.resize(n);
	close.resize(n);
	vector<int> stk;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			if (!stk.empty()) g[stk.back()].push_back(i);
			stk.push_back(i);
		}
		if (s[i] == ')') {
			close[stk.back()] = i;
			stk.pop_back();
		}
	}
	dfs(0);
	if (a[0].size() < k) {
		cout << "NO\n";
		return;
	}
	auto it = a[0].begin();
	for (int i = 0; i < k - 1; i++) {
		it = next(it);
	}
	cout << *it;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}