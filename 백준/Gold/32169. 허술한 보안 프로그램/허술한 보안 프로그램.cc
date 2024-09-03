#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define MOD 998244353
#define INF 987654321987654321LL
#define all(x) x.begin(),x.end()
#define fi(x) for(i=0;i<x;i++)
#define fi1(x) for(i=1;i<=x;i++)
#define fj(x) for(j=0;j<x;j++)
#define fj1(x) for(j=1;j<=x;j++)
#define fk(x) for(k=0;k<x;k++)
#define fk1(x) for(k=1;k<=x;k++)
#define fastio() {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pq priority_queue
#define vvi vector<vector<int> >
#define X first
#define Y second
#define endl '\n'
#define int long long
#define pbds tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

using namespace __gnu_pbds;
using namespace std;
typedef pair<int,int> P;
typedef complex<double> cpx;
const double pi = acos(-1);

int n;
int a[3005], b[3005];
int ans[3005];

signed main() {
    int i, j;

    cin >> n;
    if (n == 1) {
        cout << "! 0" << endl;
        return 0;
    }

    vector<vector<int> > adj(n + 1); // A그룹->B그룹 간선만

    fi(n) {
        fj(n) {
            if ((i | j) == i + j) {
                adj[i].pb(j);
            }
        }
    }

    vector<int> visited(n + 1);
    vector<int> l(n + 1, -1), r(n + 1, -1); // 각각 l->r, r->l
    function<int(int)> dfs = [&](int now) {
        visited[now] = 1;
        for (auto next: adj[now]) {
            if (r[next] == -1 || (!visited[r[next]] && dfs(r[next]))) { // 매칭이 안 됐거나 다른 정점과 매칭 가능할 때
                l[now] = next;
                r[next] = now;
                return 1;
            }
        }
        return 0;
    };

    fi(n) {
        if (l[i] == -1) {
            fill(all(visited), 0);
            dfs(i);
        }
    }

    cout << "? ";
    fi(n) cout << i << " ";
    cout << endl;

    fi(n) cin >> a[i];

    cout << "? ";
    fi(n) cout << l[i] << " ";
    cout << endl;

    fi(n) cin >> b[i];

    fi(n) {
        for (j = 15; j >= 0; j--) {
            if ((i & (1LL << j)) == 0) {
                int gab = (a[i] & (1LL << j)) != 0;
                ans[i] |= (gab << j);
            }
            if ((l[i] & (1LL << j)) == 0) {
                int gab = (b[i] & (1LL << j)) != 0;
                ans[i] |= (gab << j);
            }
        }
    }

    cout << "! ";
    fi(n) cout << ans[i] << " ";
    cout << endl;
}
