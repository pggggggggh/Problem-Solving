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

int n,k;
int ar[1005][1005];
int mx[1005][1005]; // i번째 줄에서 j개 뽑았을때 최대
int mxdp[1005][5005];
int dp[1005][5005];

void getmax(int row)
{
    int i,j;
    int *a = ar[row];

    int iter = min(k,n/3);
    for (i=1;i<=n;i++) {
        for (j=0;j<=iter;j++) {
            mxdp[i][j] = max(mxdp[i][j - 1], mxdp[i - 1][j]);
            if (i>=3 && j>=1) mxdp[i][j] = max(mxdp[i][j], mxdp[i - 3][j - 1] + a[i] + a[i - 1] + a[i - 2]);

            if (i == n) {
                mx[row][j] = mxdp[i][j];
            }
        }
    }
}

signed main()
{
    fastio();
    int i,j;

    cin>>n>>k;

    fi1(n) {
        fj1(n) {
            cin>>ar[i][j];
        }
        getmax(i);
    }

    for (i=1;i<=n;i++) { // dp[i][j] = i번째까지 j개 이하 뽑았을때 최대
        fj1(k) {
            int lo=0, hi=min(j,n/3);

            while (hi-lo >= 3) {
                int p = (lo * 2 + hi) / 3;
                int q = (lo + hi * 2) / 3;

                if (dp[i - 1][j - p] + mx[i][p] < dp[i - 1][j - q] + mx[i][q]) {
                    lo = p;
                } else {
                    hi = q;
                }
            }
            dp[i][j] = dp[i][j-1];
            for (int l=lo;l<=hi;l++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - l] + mx[i][l]);
            }
        }
    }
    cout<<dp[n][k];
}