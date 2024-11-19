#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
using namespace std;
using pi = pair<int, int>;

int n, k;
int vis[15];
unordered_map<string, vector<string>> adj;
unordered_map<string, pi> deg; // {in,out}
vector<string> vs;
string cur;

void recur(int now)
{
	if (now == k - 1) {
		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				string v = cur.substr(1, cur.size() - 1) + (char)('A' + i);
				adj[cur].push_back(v);
				deg[cur].second++;
				deg[v].first++;
			}
		}
		vs.push_back(cur);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		vis[i] = 1;
		cur.push_back('A' + i);
		recur(now + 1);
		cur.pop_back();
		vis[i] = 0;
	}
}

vector<string> path;

void dfs(string u)
{
	while (!adj[u].empty()) {
		string v = adj[u].back();
		adj[u].pop_back();
		dfs(v);
	}
	path.push_back(u);
}

void solve()
{
	cin >> n >> k;
	recur(0);
	string s = "";
	for (int i = 0; i < k - 1; i++) s += ('A' + i);
	dfs(s);
	int goal = 1;
	for (int i = n - k + 1; i <= n; i++) {
		goal *= i;
	}
	if (path.size() != goal + 1) {
		cout << "NO";
		return;
	}
	cout << "YES\n";
	reverse(all(path));
	for (int i = 1; i < path.size(); i++) {
		cout << path[i - 1] << path[i].back() << ' ';
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}