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

using namespace std;
typedef pair<int, int> P;

struct Edge
{
    int next,dist;
};

int n,m;
vector<Edge> adj[20001];
int indegree[20001];
int dp[20001];
vector<Edge> rev[20001];
int visited[20001];
set<pair<int,int> > ans;

void dfs(int now)
{
    visited[now] = 1;
    for (Edge e:rev[now]) {
        int prev = e.next;
        int dist = e.dist;

        if (dp[prev]+dist == dp[now]) {
            ans.insert(mp(prev, now));
            if (!visited[prev]) dfs(prev);
        }
    }
}


signed main()
{
    fastio();
    int i,j;

    cin>>n>>m;
    fi(m) {
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].pb(Edge{y,z});
        rev[y].pb(Edge{x, z});
        indegree[y]++;
    }

    queue<int> q;
    fi1(n) {
        if (indegree[i]==0) q.push(i);
    }

    int s,e;
    cin>>s>>e;
    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (Edge e:adj[now]) {
            int next=e.next;
            int dist=e.dist;

            if (dp[now]+dist > dp[next]) {
                dp[next] = dp[now]+dist;
                //path[next].clear();
                //path[next].pb(now);
            } else if (dp[now]+dist == dp[next]) {
                //path[next].pb(now);
            }
            indegree[next]--;
            if (indegree[next] == 0) q.push(next);
        }
    }

    dfs(e);
    cout<<dp[e]<<"\n"<<ans.size();
}