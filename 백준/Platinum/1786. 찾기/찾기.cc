#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int,int>;

namespace kmp {
    static vector<int> failure_func(const string &s) {
        // the length of the longest matching prefix and suffix
        vector<int> fail(s.size());
        for (int i = 1, j = 0; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) j = fail[j - 1];
            if (s[i] == s[j]) fail[i] = ++j;
        }
        return fail;
    }

    static vector<int> match(const string &a, const string &b) {
        vector<int> res;
        vector<int> fail = failure_func(b);
        for (int i = 0, j = 0; i < a.size(); i++) {
            while (j > 0 && a[i] != b[j]) j = fail[j - 1];
            if (a[i] == b[j]) {
                if (j == b.size() - 1) {
                    res.push_back(i - b.size() + 1 + 1);
                    j = fail[j];
                } else j++;
            }
        }
        return res;
    }

    static vector<int> z_func(const string &s) {
        vector<int> z(s.size());
        z[0] = s.size();
        int l = 0, r = 0; // [l,r)
        for (int i = 1; i < s.size(); i++) {
            if (i < r) z[i] = min(r - i, z[i - l]);
            while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }
};

signed main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    auto res = kmp::match(a, b);
    cout << res.size() << '\n';
    for (auto &x: res) cout << x << '\n';
}
