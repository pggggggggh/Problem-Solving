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

int n,m;

signed main()
{
    fastio();
    int i,j;

    cin>>n>>m;
    vector<vector<int>> a(n, vector<int>(m));
    fi(n) {
        fj(m) cin>>a[i][j];
        sort(v(a[i]));
    }
    vector<int> ptrs(n, 0);

    pq<pair<int, P>, vector<pair<int, P>>, greater<>> q;
    set<int> s;
    fi(n) {
        q.push({a[i][0], {i, 0}});
        s.insert(a[i][0]);
    }

    int ans = *s.rbegin() - *s.begin();
    while (!q.empty()) {
        auto [now, p] = q.top();
        auto [x, y] = p;
        q.pop();

        if (y == m-1) continue;

        s.erase(a[x][y]);
        s.insert(a[x][y+1]);
        q.push({a[x][y + 1], {x, y + 1}});

        ans = min(ans, *s.rbegin() - *s.begin());
    }
    cout<<ans;
}