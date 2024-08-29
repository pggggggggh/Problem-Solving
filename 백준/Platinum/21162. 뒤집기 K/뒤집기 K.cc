#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int,int>;

struct suffix_array {
    vector<int> sa, lcp;
    // both include empty prefix at index 0, lcp[x] = lcp of sa[x], sa[x-1]

    suffix_array(vector<int> &s, int lim = 200001) {
        int n = s.size() + 1, k = 0, a, b;
        vector<int> x(n), y(n), ws(max(n, lim)), rank(n);
        for (int i = 0; i < s.size(); i++) x[i] = s[i];
        sa = lcp = y, iota(all(sa), 0);
        for (int j = 0, p = 0; p < n; j = max(1LL, j * 2), lim = p) {
            p = j, iota(all(y), n - j);
            for (int i = 0; i < n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;
            fill(all(ws), 0);
            for (int i = 0; i < n; i++) ws[x[i]]++;
            for (int i = 1; i < lim; i++) ws[i] += ws[i - 1];
            for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
            swap(x, y), p = 1, x[sa[0]] = 0;
            for (int i = 1; i < n; i++)
                a = sa[i - 1], b = sa[i], x[b] =
                        (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
        }
        for (int i = 1; i < n; i++) rank[sa[i]] = i;
        for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
            for (k && k--, j = sa[rank[i] - 1];
                 s[i + k] == s[j + k]; k++);
    }
};


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    reverse(all(a));
    a.insert(a.end(),all(a));
    suffix_array _sa(a);
    auto sa = _sa.sa;
    for (int i = 1; i <= 2 * n; i++) {
        if (sa[i] && sa[i] < n && !--k) {
            for (int j = sa[i]; j < sa[i] + n; j++) cout << a[j] << ' ';
            return 0;
        }
    }
}
