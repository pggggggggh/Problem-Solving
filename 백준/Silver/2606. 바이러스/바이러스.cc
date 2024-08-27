#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;

int par[105];
int sz[105];

int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

void uni(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (y == 1) swap(x, y);
    sz[x] += sz[y];
    par[y] = x;
}

signed main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        uni(x, y);
    }
    cout << sz[1] - 1;
}
