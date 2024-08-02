#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define MOD 1000000007LL
#define INF 987654321987654321LL
#define v(x) x.begin(),x.end()
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
typedef pair<int, int> P;

int n;
int g[2005] = {0, 1, 1, 1, 2, 2};

signed main()
{
    int i,j;

    cin>>n;

    for (i=6;i<=n;i++) {
        vector<int> now(2001, 0);
        for (j=i-5;j<=i-3;j++) {
            now[g[j]] = 1;
        }
        for (j=1;j<=i-6;j++) {
            now[g[j] ^ g[i - 5 - j]] = 1;
        }
        for (j=0;j<=2000;j++) {
            if (!now[j]) {
                g[i] = j;
                break;
            }
        }
    }
    cout<<(g[n]?1:2)<<endl;
}