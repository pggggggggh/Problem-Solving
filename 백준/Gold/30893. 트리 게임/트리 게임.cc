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

int n,s,e;
vector<int> adj[100005];
vector<int> childs[100005];
int parent[100005];
int visited[100005];

void makeTree(int now)
{
    visited[now] = 1;
    for (auto next:adj[now]) {
        if (visited[next]) continue;
        childs[now].pb(next);
        parent[next] = now;
        makeTree(next);
    }
}

signed main()
{
    int i,j;

    cin>>n>>s>>e;
    fi(n-1) {
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    makeTree(s);
    int now = e;
    vector<int> path;
    while (now != s) {
        now = parent[now];
        path.pb(now);
    }
    reverse(v(path));
    int ans = 1;
    for (i=0;i<path.size();i++) {
        if (i%2==1 && childs[path[i]].size() > 1) {
            ans = 0;
            break;
        }
    }
    cout<<(ans?"First":"Second");
}