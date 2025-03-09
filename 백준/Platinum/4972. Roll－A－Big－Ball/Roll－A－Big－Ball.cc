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
typedef pair<double,double> point;
typedef pair<point, point> line;

int t;
int n;

int ccw(point a, point b, point c)
{
    point va = {b.X-a.X,b.Y-a.Y};
    point vb = {c.X-b.X,c.Y-b.Y};
    double cross = va.X * vb.Y - va.Y * vb.X;
    if (cross>0) return 1;
    if (cross<0) return -1;
    return 0;
}

bool cross(line a, line b)
{
    auto [p1,p2] = a;
    auto [p3,p4] = b;
    int c1 = ccw(p1,p2,p3) * ccw(p1,p2,p4);
    int c2 = ccw(p3,p4,p1) * ccw(p3,p4,p2);

    if (c1 == 0 && c2 == 0) {
        if (p1>p2) swap(p1,p2);
        if (p3>p4) swap(p3,p4);
        return p3 <= p2 && p1 <= p4; // a c b d, c a d b의 경우를 모두 처리 가능
    }
    return c1 <= 0 && c2 <= 0;
}

signed main()
{
    int i,j;

    while (1) {
        vector<pair<line,double>> lines;
        vector<pair<point,double>> points;
        double sx,sy,ex,ey;

        cin>>n;
        if (n==0) return 0;
        cin>>sx>>sy>>ex>>ey;
        pair<double,double> bangvec = {ex-sx,ey-sy};
        double norm = sqrt(bangvec.X * bangvec.X + bangvec.Y * bangvec.Y);
        bangvec.X /= norm;
        bangvec.Y /= norm;
        pair<double,double> bubvec = {sy-ey,ex-sx};
        double norm2 = sqrt(bubvec.X * bubvec.X + bubvec.Y * bubvec.Y);
        bubvec.X /= norm2;
        bubvec.Y /= norm2;

        int flag = 1;
        fi1(n) {
            double a,b,c,d,h;
            cin>>a>>b>>c>>d>>h;
            line f = {{a, b}, {c, d}};
            lines.pb({{{a, b}, {c, b}}, h});
            lines.pb({{{a, d}, {c, d}}, h});
            lines.pb({{{a, b}, {a, d}}, h});
            lines.pb({{{c, b}, {c, d}}, h});
            points.pb({{a,b},h});
            points.pb({{c,b},h});
            points.pb({{a,d},h});
            points.pb({{c,d},h});

            if (a < sx && sx < c && b < sy && sy < d) {
                flag = 0;
            }
            if (a < ex && ex < c && b < ey && ey < d) {
                flag = 0;
            }
        }
        if (!flag) {
            cout<<0<<endl;
            continue;
        }

        double lo = 0, hi = 1005;
        while (lo+0.000000001 < hi) {
            double r = (lo + hi) / 2;

            int able = 1;

            for (auto x:points) {
                auto [p,h] = x;
                double r2;

                if (h >= r) r2 = r;
                else r2 = sqrt(r*r-(r-h)*(r-h));

                pair v1 = {p.X-sx,p.Y-sy};
                double dotproduct = v1.X * bangvec.X + v1.Y * bangvec.Y;
                double dist2;
                if (dotproduct < 0) {
                    dist2 = (p.X - sx) * (p.X - sx) + (p.Y - sy) * (p.Y - sy);
                } else if (dotproduct > sqrt((ex-sx)*(ex-sx)+(ey-sy)*(ey-sy))) {
                    dist2 = (p.X - ex) * (p.X - ex) + (p.Y - ey) * (p.Y - ey);
                } else dist2 = v1.X * v1.X + v1.Y * v1.Y - dotproduct * dotproduct;

                if (dist2 < r2*r2) {
                    able = 0;
                    break;
                }
            }
            for (auto x:lines) {
                if (!able) break;
                auto [l,h] = x;
                double r2;

                if (h >= r) r2 = r;
                else r2 = sqrt(r*r-(r-h)*(r-h));

                // 시점, 종점 체크
                if (l.X.X == l.Y.X) { // 세로선
                    if (l.X.Y <= sy && sy <= l.Y.Y && abs(sx - l.X.X) < r2) {
                        able = 0;
                        break;
                    }
                    if (l.X.Y <= ey && ey <= l.Y.Y && abs(ex - l.X.X) < r2) {
                        able = 0;
                        break;
                    }
                } else { // 가로선
                    if (l.X.X <= sx && sx <= l.Y.X && abs(sy - l.X.Y) < r2) {
                        able = 0;
                        break;
                    }
                    if (l.X.X <= ex && ex <= l.Y.X && abs(ey - l.X.Y) < r2) {
                        able = 0;
                        break;
                    }
                }

                if (cross({mp(sx,sy),mp(ex,ey)},l)) {
                    able = 0;
                    break;
                }
            }
            if (able) lo = r;
            else hi = r;
        }
        cout.precision(12);
        cout<<fixed<<lo<<endl;
    }
}