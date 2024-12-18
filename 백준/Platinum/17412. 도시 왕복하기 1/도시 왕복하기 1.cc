#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 987654321LL
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
#define pos(y,x) (y*m+x+1) // 1부터 시작
#define int long long
#define QQ cout<<"!";

using namespace std;
typedef pair<int, int> P;

struct Edge {
    int to, c, f;
    Edge* rev;

    Edge(int to_, int c_) {
        to = to_;
        c = c_;
        f = 0;
        rev = nullptr;
    }

    int left() {
        return c - f;
    }
};

int n,p;
vector<Edge*> adj[1000];
int s,e;

signed main()
{
    int i,j;

    cin>>n>>p;
    fi(p) {
        int x,y;
        cin>>x>>y;
        Edge* e1 = new Edge(y, 1);
        Edge* e2 = new Edge(x, 0);
        e1->rev = e2;
        e2->rev = e1;
        adj[x].pb(e1);
        adj[y].pb(e2); // adj는 무슨 일이 있어도 양쪽
    }
    s = 1;
    e = 2;

    int ans=0;
    while (1) {
        vector<Edge*> prev(n+1,nullptr); // i 올때 타고온 간선
        queue<int> q;
        q.push(s);
        while (!q.empty() && !prev[e]) { // 싱크에 도달하면 종료
            int now = q.front();
            q.pop();

            for (auto edge:adj[now]) {
                int next = edge->to;
                if (edge->left() > 0 && !prev[next]) { // 방문하지 않은 증가경로
                    q.push(next);
                    prev[next] = edge;
                }
            }
        }
        if (!prev[e]) break; // 증가경로 없음

        int flow = INF;
        int now = e;
        while (now != s) {
            flow = min(flow, prev[now]->left());
            now = prev[now]->rev->to;
        }

        now = e;
        while (now != s) {
            prev[now]->f += flow;
            prev[now]->rev->f -= flow;
            now = prev[now]->rev->to;
        }
        ans += flow;
    }
    cout<<ans;
}