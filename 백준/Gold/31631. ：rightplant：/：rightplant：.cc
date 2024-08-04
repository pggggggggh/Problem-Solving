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

signed main()
{
    int i,j;

    cin>>n;

    vector<int> ans(n+1);
    int spos;

    if (n==2) {
        cout<<"1 2";
        return 0;
    }
    if (n==3) {
        cout<<"2 1 3";
        return 0;
    }

    if (n%4 == 3) {
        spos = (n+1)/2;
        ans[spos] = 1;
        ans[spos-1] = 2;
        ans[spos+1] = 3;

        int flag = 1;
        for (i=spos-2;i>=1;i--) {
            ans[i] = ans[i+1] + 2 + flag;
            flag *= -1;
        }
        flag = -1;
        for (i=spos+2;i<=n;i++) {
            ans[i] = ans[i-1] + 2 + flag;
            flag *= -1;
        }
    }
    if (n%4 == 0) {
        spos = n/2+1;
        ans[spos] = 1;
        ans[spos-1] = 2;
        ans[spos-2] = 3;

        int flag = 1;
        for (i=spos-3;i>=1;i--) {
            ans[i] = ans[i+1] + 2 + flag;
            flag *= -1;
        }
        flag = 1;
        for (i=spos+1;i<=n;i++) {
            ans[i] = ans[i-1] + 2 + flag;
            flag *= -1;
        }
    }
    if (n%4 == 1) {
        spos = (n+1)/2;
        ans[spos] = 1;
        ans[spos+1] = 2;
        ans[spos-1] = 3;

        int flag = -1;
        for (i=spos-2;i>=1;i--) {
            ans[i] = ans[i+1] + 2 + flag;
            flag *= -1;
        }
        flag = 1;
        for (i=spos+2;i<=n;i++) {
            ans[i] = ans[i-1] + 2 + flag;
            flag *= -1;
        }
    }
    if (n%4 == 2) {
        spos = n/2;
        ans[spos] = 1;
        ans[spos+1] = 2;
        ans[spos+2] = 3;

        int flag = 1;
        for (i=spos-1;i>=1;i--) {
            ans[i] = ans[i+1] + 2 + flag;
            flag *= -1;
        }
        flag = 1;
        for (i=spos+3;i<=n;i++) {
            ans[i] = ans[i-1] + 2 + flag;
            flag *= -1;
        }
    }

    fi1(n) cout<<ans[i]<<" ";
}