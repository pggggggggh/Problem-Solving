#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = array<int, 2>;
using matrix = vector<vector<int> >;

const int MOD = 1000000007;

matrix operator*(const matrix &a, const matrix &b) {
    matrix res(8, vector<int>(8));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return res;
}

matrix a(8, vector<int>(8));

void addEdge(int u, int v) {
    a[u][v] = 1;
    a[v][u] = 1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(2, 3);
    addEdge(2, 4);
    addEdge(3, 4);
    addEdge(3, 5);
    addEdge(4, 5);
    addEdge(4, 6);
    addEdge(5, 7);
    addEdge(6, 7);

    int d;
    cin >> d;
    matrix piv = a, res(8, vector<int>(8));
    for (int i = 0; i < 8; i++) res[i][i] = 1;
    while (d) {
        if (d & 1) res = res * piv;
        piv = piv * piv;
        d >>= 1;
    }
    cout << res[0][0];
}
