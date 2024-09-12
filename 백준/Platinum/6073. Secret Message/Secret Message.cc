#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int,int>;

struct node {
    node *nxt[2];
    int cnt, end;

    node(): cnt(0), end(0) {
        nxt[0] = nxt[1] = NULL;
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    node *root = new node();
    for (int i = 0; i < m; i++) {
        int k, x;
        cin >> k;
        node *cur = root;
        for (int j = 0; j < k; j++) {
            cin >> x;
            if (cur->nxt[x] == NULL) cur->nxt[x] = new node();
            cur = cur->nxt[x];
            cur->cnt++;
        }
        cur->end++;
    }

    for (int i = 0; i < n; i++) {
        int k, x;
        cin >> k;
        node *cur = root;
        int res = 0;
        for (int j = 0; j < k; j++) {
            cin >> x;
            if (cur == NULL) continue;
            res += cur->end;
            cur = cur->nxt[x];
        }
        if (cur != NULL) res += cur->cnt;
        cout << res << '\n';
    }
}
