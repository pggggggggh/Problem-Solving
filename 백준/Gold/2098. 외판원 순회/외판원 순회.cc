#include <bits/stdc++.h>
#define MOD 1000000000
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

using namespace std;
typedef pair<int, int> P;
int n;
int w[20][20];
int startpoint;
int dp[150000][17]; // state, now

int tsp(int state, int now)
{
    int i,j;
    int cnt=0;
    int &ret = dp[state][now];

    //cout << "현재 " << state << " " <<  now << endl;


    if (ret != -1) return ret;


    for (i=1;i<=n;i++) {
        if ((state & (1<<i)) != 0) cnt++;
    }

    if (cnt == n) {
        return ret = w[now][startpoint];
    }

    ret = INF;

    for (i=1;i<=n;i++) {
        if (w[now][i] == INF || (state&(1<<i)) != 0) continue;
        ret = min(ret,tsp((state|(1<<i)),i)+w[now][i]);
    }
    return ret;
}

signed main()
{
    int i,j;
    memset(dp,-1,sizeof(dp));

    cin >> n;
    fi1 (n) {
        fj1 (n) {
            cin >> w[i][j];
            if (w[i][j] == 0) w[i][j] = INF;
        }
    }

    startpoint = 1;
    cout << tsp(1<<1,1) << "\n";

}