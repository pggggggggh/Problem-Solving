#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int,int>;

array<vector<int>, 2> manacher(const string &s) {
    /* max even palindrome around i : p[0][i] * 2
     * max odd palindrome around i : p[1][i] * 2 + 1 */
    int n = s.size();
    array p = {vector<int>(n + 1), vector<int>(n)};
    for (int z = 0; z < 2; z++) {
        for (int i = 0, l = 0, r = 0; i < n; i++) {
            int t = r - i + !z;
            if (i < r) p[z][i] = min(t, p[z][l + t]);
            int L = i - p[z][i], R = i + p[z][i] - !z;
            while (L >= 1 && R + 1 < n && s[L - 1] == s[R + 1])
                p[z][i]++, L--, R++;
            if (R > r) l = L, r = R;
        }
    }
    return p;
}

signed main() {
    string s;
    cin >> s;
    auto p = manacher(s);
    int res = 0;
    for (int i = 0; i < s.size(); i++) res += p[0][i] + p[1][i] + 1;
    cout << res;
}
