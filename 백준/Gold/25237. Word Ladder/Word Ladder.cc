#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution dis_idx(0, 9), dis_char(0, 25);
	int n;
	cin >> n;
	set<string> st;
	string cur = "aaaaaaaaaa";
	st.insert(cur);
	while (n--) {
		while (1) {
			int idx = dis_idx(gen), c = dis_char(gen);
			char realorg = cur[idx];
			cur[idx] = 'a' + c;
			int cnt = 0;
			for (int i = 0; i < 10; i++) {
				char orig = cur[i];
				for (int j = 0; j < 26; j++) {
					cur[i] = 'a' + j;
					if (st.count(cur)) cnt++;
				}
				cur[i] = orig;
			}

			if (cnt == 1) break;
			cur[idx] = realorg;
		}
		st.insert(cur);
		cout << cur << '\n';
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}