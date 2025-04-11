#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 987654321987654321LL
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

int n,m,q;
vector<int> adj[200000];
vector<P> edges;
int dis[200000]; // 끊어진 엣지
int par[200000];
int sz[200000];

int find(int x)
{
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

void uni(int x, int y)
{
    x=find(x);
    y=find(y);
    if (x==y) return;
    par[y] = x;
    sz[x] += sz[y];
}

signed main()
{
    fastio();
    int i,j;

    cin>>n>>m>>q;
    edges.resize(m+1);
    fi1(m) {
        int x,y;
        cin>>x>>y;
        edges[i] = {x, y};
    }
    fi1(n) {
        sz[i] = 1;
        par[i] = i;
    }

    vector<int> query;
    query.resize(q);
    fi(q) {
        cin>>query[i];
        dis[query[i]] = 1;
    }
    reverse(v(query));

    fi1(m) {
        if (dis[i]) continue;
        uni(edges[i].X, edges[i].Y);
//        cout<<edges[i].X<<" "<<edges[i].Y<<" connect\n";
//        cout<<sz[par[3]]<<"!"<<endl;
    }


    int ans=0;
    for (auto q:query) {
        if (find(edges[q].X) != find(edges[q].Y)) {
            ans += sz[par[edges[q].X]] * sz[par[edges[q].Y]];
        }
//        cout << sz[par[edges[q].X]] <<" "<< sz[par[edges[q].Y]] << endl;

        uni(edges[q].X, edges[q].Y);
//
//        fi1(n) {
//            cout<<sz[i]<<endl;
//        }
    }
    cout<<ans;
}