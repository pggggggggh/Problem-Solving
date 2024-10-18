#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
	string s;
	cin >> s;
	stack<char> stk;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') cout << s[i];
		else if (s[i] == ')') {
			while (!stk.empty() && stk.top() != '(') {
				cout << stk.top();
				stk.pop();
			}
			stk.pop();
		} else if (s[i] == '(') {
			stk.push(s[i]);
		} else {
			while (!stk.empty() && (stk.top() == '*' || stk.top() == '/' || (stk.top() != '(' && (s[i] == '+' || s[i] == '-')))) {
				cout << stk.top();
				stk.pop();
			}
			stk.push(s[i]);
		}
	}
	while (!stk.empty()) {
		cout << stk.top();
		stk.pop();
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}