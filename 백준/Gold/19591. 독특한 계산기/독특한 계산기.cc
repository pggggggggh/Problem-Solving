#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int,int>;

string calc(array<string, 3> s) {
    int a = stol(s[0]);
    int b = stol(s[2]);
    int res = 0;
    if (s[1] == "+") {
        res = a + b;
    } else if (s[1] == "-") {
        res = a - b;
    } else if (s[1] == "/") {
        res = a / b;
    } else if (s[1] == "*") {
        res = a * b;
    }
    return to_string(res);
}

signed main() {
    string s;
    deque<string> dq;
    cin >> s;
    int start = 0;
    for (int i = 0; i <= s.size(); i++) {
        if (i && (i == s.size() || string("+-*/").find(s[i]) != string::npos)) {
            dq.push_back(s.substr(start, i - start));
            if (i < s.size()) dq.push_back({s[i]});
            start = i + 1;
        }
    }
    if (dq.size() == 1) {
        cout << to_string(stol(s));
        return 0;
    }
    while (dq.size() > 3) {
        array<string, 3> front, back;
        for (int i = 0; i < 3; i++) front[i] = dq[i];
        for (int i = 0; i < 3; i++) back[2 - i] = dq[dq.size() - 1 - i];
        bool bf = string("*/").find(front[1]) != string::npos;
        bool bb = string("*/").find(back[1]) != string::npos;
        string sf = calc(front), sb = calc(back);
        int res = 0;
        if (bf == bb) res = stol(sf) < stol(sb);
        else res = bb == 1;
        if (res == 0) {
            for (int i = 0; i < 3; i++) dq.pop_front();
            dq.push_front(sf);
        } else {
            for (int i = 0; i < 3; i++) dq.pop_back();
            dq.push_back(sb);
        }
    }
    cout << calc({dq[0], dq[1], dq[2]});
}
