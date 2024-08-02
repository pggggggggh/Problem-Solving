#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 98765432198765432LL
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
#define X first
#define Y second
#define endl '\n'
#define DEBUG 0
#define int long long

using namespace std;
typedef pair<int, int> P;

int n;
int win[2000];

signed main()
{
    win[1] = 1;
    win[3] = 1;

    cin>>n;

    for (int i=4;i<=n;i++) {
        win[i] = !(win[i - 1] || win[i - 3]); // 1이나 3을 가져갔을 때 상대가 이긴다면
    }
    cout << (win[n] ? "SK" : "CY");
}