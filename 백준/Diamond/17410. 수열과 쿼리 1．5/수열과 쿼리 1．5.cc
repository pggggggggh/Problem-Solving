#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define MOD 998244353LL
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

using namespace std;
typedef pair<int, int> P;

int n,q;
int a[100005];
vector<int> bucket[400];

signed main()
{
    fastio();
    int i,j;

    cin>>n;
    int sq = 1000;

    fi1(n) {
        cin>>a[i];
        bucket[i/sq].pb(a[i]);
    }
    for (i=0;i<=n/sq;i++) {
        sort(v(bucket[i]));
    }

    cin>>q;

    fi(q) {
        int t;
        cin>>t;
        if (t == 2) {
            int l,r,k;
            cin>>l>>r>>k;

            int ans = 0;
            while (l%sq != 0 && l<=r) {
                if (a[l] > k) ans++;
                l++;
            }
            while ((r+1)%sq != 0 && l<=r) {
                if (a[r] > k) ans++;
                r--;
            }
            while (l<=r) {
                int tmp = bucket[l / sq].end() - upper_bound(v(bucket[l / sq]), k);
                ans += tmp;
                l += sq;
            }

            cout<<ans<<endl;
        }
        else {
            int idx,val;
            cin>>idx>>val;

            bucket[idx / sq].erase(lower_bound(v(bucket[idx / sq]), a[idx]));
            bucket[idx / sq].insert(lower_bound(v(bucket[idx / sq]), val), val);

            a[idx] = val;
        }
    }
}