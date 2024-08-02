#include <bits/stdc++.h>
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

int n,c,q;
int a[300005];
vector<int> bucket(605, -1); // {과반수 값, 등장 횟수}
int bucketcnt[605][10005];
int bucketpsum[605][10005];
vector<P> p;

signed main()
{
    fastio();
    int i,j;

    cin>>n>>c;
    fi1(n) {
        cin>>a[i];
        p.pb({a[i], i});
    }
    int sq = sqrt(n);
    fi1(n/sq) {
        for(j=(i-1)*sq+1;j<=i*sq;j++) {
            bucketcnt[i][a[j]]++;
        }
        fj1(c) {
            bucketpsum[i][j] = bucketpsum[i - 1][j] + bucketcnt[i][j];
            if (bucketcnt[i][j] > sq/2) {
                bucket[i] = j;
            }
        }
    }

    sort(v(p));

    cin>>q;
    while (q--) {
        int s,e;
        cin>>s>>e;

        set<int> hubo;
        vector<int> cnt(c + 1, 0);
        int sbucket = (s + (sq - 1) * 2) / sq;
        int ebucket = e / sq;

        if (sbucket <= ebucket) {
            for (i = sbucket; i <= ebucket; i++) {
                if (bucket[i] == -1) continue;
                hubo.insert(bucket[i]);
            }
            for (i = s; i <= (sbucket-1) * sq; i++) {
                hubo.insert(a[i]);
                cnt[a[i]]++;
            }
            for (i = ebucket * sq + 1; i <= e; i++) {
                hubo.insert(a[i]);
                cnt[a[i]]++;
            }
            for (auto x:hubo) {
                cnt[x] += bucketpsum[ebucket][x] - bucketpsum[sbucket - 1][x];
            }
        } else {
            for (i=s;i<=e;i++) {
                hubo.insert(a[i]);
                cnt[a[i]]++;
            }
        }

//        cout<<sbucket<<" "<<ebucket<<endl;
        int ans = -1;
        for (auto x:hubo) {
//            cout<<x<<":"<<cnt[x]<<endl;
            if (cnt[x] > (e-s+1)/2) {
                ans = x;
                break;
            }
        }

        if (ans == -1) cout<<"no\n";
        else cout<<"yes "<<ans<<endl;
    }
}