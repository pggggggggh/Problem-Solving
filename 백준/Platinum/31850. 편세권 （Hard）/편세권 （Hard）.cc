#include <bits/stdc++.h>
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
#define DEBUG 0
#define dig(x) ((int)(x)-'0')
#define int long long
#define QQ cout<<"!";

using namespace std;
typedef pair<int, int> P;

#define SZ 5000000

int n,m,r,c;
vector<pair<P,int>> a; // -1이면 편의점
vector<pair<P,int>> houses;
int ans[500005];
int sz;
int seg[SZ];

void init()
{
    sz = 1;
    while (sz < n) sz *= 2;
    for (int i=1;i<=2*sz-1;i++) seg[i] = INF;
}

int c1(pair<P,int> x, pair<P,int> y)
{
    if (x.X == y.X) return x.Y < y.Y;
    if (x.X.Y == y.X.Y) return x.X.X > y.X.X;
    return x.X.Y > y.X.Y;
}

void update(int x, int val, int now=1, int l=1, int r=sz)
{
    if (r<x || x<l) return;
    if (l==r && x==l) {
        seg[now] = min(seg[now], val);
        return;
    }
    int mid = (l + r) / 2;
    update(x, val, now * 2, l, mid);
    update(x, val, now * 2 + 1, mid + 1, r);
    seg[now] = min(seg[now * 2], seg[now * 2 + 1]);
}

int query(int x, int y, int now=1, int l=1, int r=sz)
{
    if (r<x || y<l) return INF;
    if (x<=l && r<=y) return seg[now];
    int mid = (l + r) / 2;
    return min(query(x, y, now * 2, l, mid), query(x, y, now * 2 + 1, mid + 1, r));
}

signed main()
{
    fastio();
    int i,j;

    cin>>n>>m>>r>>c;

    fi1(r) {
        int x,y,z;
        cin>>x>>y>>z;
        a.pb({{x, y}, z});
        houses.pb({{x, y}, z});
    }
    sort(v(houses), c1);
    fi1(c) {
        int x,y;
        cin>>x>>y;
        a.pb({{x, y}, -1});
    }
    for (i=0;i<houses.size()+1;i++) ans[i] = INF;

    init();
    sort(v(a), c1);
    for (auto &[pos,k]:a) {
        if (k == -1) update(pos.X, pos.X + pos.Y);
        else {
            int idx = lower_bound(v(houses), mp(mp(pos.X, pos.Y), -1LL), c1) - houses.begin();
            ans[idx] = min(ans[idx], query(pos.X, n) - (pos.X + pos.Y));
        }

        pos.X = n + 1 - pos.X;
    }

    init();
    sort(v(a), c1);
    for (auto &[pos,k]:a) {
        if (k == -1) update(pos.X, pos.X + pos.Y);
        else {
            int idx = lower_bound(v(houses), mp(mp(n + 1 - pos.X, pos.Y), -1LL), c1) - houses.begin();
            ans[idx] = min(ans[idx], query(pos.X, n) - (pos.X + pos.Y));
        }

        pos.Y = m + 1 - pos.Y;
    }

    init();
    sort(v(a), c1);
    for (auto &[pos,k]:a) {
        if (k == -1) update(pos.X, pos.X + pos.Y);
        else {
            int idx = lower_bound(v(houses), mp(mp(n + 1 - pos.X, m + 1 - pos.Y), -1LL),c1) - houses.begin();
            ans[idx] = min(ans[idx], query(pos.X, n) - (pos.X + pos.Y));
        }

        pos.X = n + 1 - pos.X;
    }

    init();
    sort(v(a), c1);
    for (auto &[pos,k]:a) {
        if (k == -1) update(pos.X, pos.X + pos.Y);
        else {
            int idx = lower_bound(v(houses), mp(mp(pos.X, m + 1 - pos.Y), -1LL), c1) - houses.begin();
            ans[idx] = min(ans[idx], query(pos.X, n) - (pos.X + pos.Y));
        }

        pos.Y = m + 1 - pos.Y;
    }

    int aans = INF;
    fi(houses.size()) {
        aans = min(aans, houses[i].Y * ans[i]);
    }
    cout<<aans;
}