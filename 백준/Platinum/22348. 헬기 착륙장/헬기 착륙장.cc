#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 98765432198765432LL
#define int long long
#define ms(x,y) memset(x,y,sizeof(x))
#define v(x) x.begin(),x.end()
#define fi(x) for(i=0;i<x;i++)
#define fii(x) for(int i=0;i<x;i++)
#define fi1(x) for(i=1;i<=x;i++)
#define fii1(x) for(int i=1;i<=x;i++)
#define fj(x) for(j=0;j<x;j++)
#define fj1(x) for(j=1;j<=x;j++)
#define fk(x) for(k=0;k<x;k++)
#define fk1(x) for(k=1;k<=x;k++)
#define fastio() {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define DEBUG 0

using namespace std;
typedef pair<int, int> P;

int a,b;
int dp[1000][60000];
int psum[1000][60000];

int recur(int now, int used) // now까지 그렸고, 사용한 a의 양 used
{
    int &ret = dp[now][used];
    if (ret != -1) return ret;

    int bused = (now * (now + 1) / 2 - (used));

    if (now == 0 && used == 0) return ret=1;
    if (now == 0) return ret=0;

    ret = 0;
    if (bused >= now) ret += recur(now - 1,used);
    ret %= MOD;
    if (used >= now) ret += recur(now - 1, used - (now));
    ret %= MOD;

    //cout<<now<<" "<<used<<" : "<<ret<<endl;

    return ret;
}

signed main()
{
    fastio();
    int i,j;
    int t;

    cin>>t;

    memset(dp, -1, sizeof(dp));
    for (i=0;i<=500;i++) {
        for (j=0;j<=50000;j++) {
            recur(i,j);
        }
    }

    for (i=1;i<=500;i++) {
        psum[i][0] = dp[i][0];
        for (j=1;j<=50000;j++) {
            psum[i][j] = (psum[i][j-1] + dp[i][j])%MOD;
        }
    }

    while (t--) {
        cin>>a>>b;
        int ans=0;
        for (i=1;i<=500;i++) {
            int sum = i*(i+1)/2;
            if (sum > a+b) break;
            if (a>b) swap(a,b);
            /*for (j=max(0LL,sum-b);j<=a;j++) {
                ans += dp[i][j];
            }*/
            int toadd = psum[i][a] - (max(0LL, sum - b) == 0 ? 0 : psum[i][max(0LL, sum - b) - 1]);
            if (toadd < 0) toadd += MOD;
            ans = (ans+toadd)%MOD;
        }
        cout<<ans<<"\n";
    }
}