#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int,int>;

struct mos {
    using S = int; // type of array
    using T = int; // type of query result

    struct query {
        int s, e, idx;
    };

    int n, m, sq;
    vector<S> a;
    vector<query> Q;

    vector<int> cnt;

    void add(T &cur, int idx, bool end) {
        if (cnt[a[idx]] == 0) cur++;
        cnt[a[idx]]++;
    }

    void del(T &cur, int idx, bool end) {
        cnt[a[idx]]--;
        if (cnt[a[idx]] == 0) cur--;
    }

    mos(const vector<S> &a) {
        n = a.size();
        m = 0;
        sq = sqrt(n);
        cnt = vector<int>(1000005);
        this->a = a;
    }

    void add_query(int s, int e) {
        Q.push_back({s, e, m});
        m++;
    }

    vector<T> process_queries() {
        sort(all(Q), [&](const query &x, const query &y) -> bool {
            if (x.s / sq == y.s / sq) return x.e < y.e;
            return x.s / sq < y.s / sq;
        });
        int s = 0, e = -1;
        vector<T> res(m);
        T cur = 0;
        for (auto &q: Q) {
            while (s < q.s) del(cur, s++, 0);
            while (s > q.s) add(cur, --s, 0);
            while (e < q.e) add(cur, ++e, 1);
            while (e > q.e) del(cur, e--, 1);
            res[q.idx] = cur;
        }
        return res;
    }
};

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    mos mo(a);
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        mo.add_query(x, y);
    }
    auto res = mo.process_queries();
    for (int i = 0; i < res.size(); i++) cout << res[i] << '\n';
}
