#include <bits/stdc++.h>
#define MOD 1000000007LL
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
#define pos(y,x) ((y)*m+(x)+1) // 1부터 시작
#define dig(x) ((int)(x)-'0')
#define int long long
#define QQ cout<<"!";

using namespace std;
typedef pair<int, int> P;

#define N 110000

int n,m;
vector<int> childs[N];
int c[N], l[N];
pq<int> q[N];
int idx[N];
int sum[N]; // idx 기준

void merge(int x, int y) // 합쳐서 idx[x]로 가게끔
{
    if (q[idx[x]].size() < q[idx[y]].size()) {
        swap(idx[x], idx[y]);
    }

    x = idx[x];
    y = idx[y];

    while (!q[y].empty()) {
        int toput = q[y].top();
        q[y].pop();
        if (sum[x] + toput <= m) {
            q[x].push(toput);
            sum[x] += toput;
        } else {
            if (q[x].top() > toput) {
                sum[x] -= q[x].top();
                q[x].pop();
                sum[x] += toput;
                q[x].push(toput);
            }
        }
    }
}

int ans = 0;

void recur(int now)
{
    for (auto child:childs[now]) {
        recur(child);
        merge(now, child);
    }

    ans = max(l[now] * (int)q[idx[now]].size(), ans);
}

signed main()
{
    int i,j;
    int root;

    cin>>n>>m;
    fi1(n) {
        int x;
        cin >> x >> c[i] >> l[i];
        idx[i] = i;
        q[i].push(c[i]);
        sum[i] += c[i];

        if (x == 0) root = i;
        childs[x].pb(i);
    }
    recur(root);

    cout<<ans;
}