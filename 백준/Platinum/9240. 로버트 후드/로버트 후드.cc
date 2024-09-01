#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int,int>;

struct point {
    int x, y; // double if needed

    bool operator<(const point &p) const {
        return tie(x, y) < tie(p.x, p.y);
    }

    bool operator<=(const point &p) const {
        return tie(x, y) <= tie(p.x, p.y);
    }

    bool operator>(const point &p) const {
        return tie(x, y) > tie(p.x, p.y);
    }

    bool operator>=(const point &p) const {
        return tie(x, y) >= tie(p.x, p.y);
    }

    point operator-(const point &b) const {
        return {x - b.x, y - b.y};
    }

    int operator*(const point &b) const { // dot
        return x * b.x + y * b.y;
    }

    int operator/(const point &b) const { // cross
        return x * b.y - y * b.x;
    }
};

typedef array<point, 2> line;

int ccw(point a, point b, point c) {
    point va = {b.x - a.x, b.y - a.y};
    point vb = {c.x - b.x, c.y - b.y};
    int cross = va / vb;
    if (cross > 0) return 1;
    if (cross < 0) return -1;
    return 0;
}

bool cross(line a, line b) {
    auto [p1,p2] = a;
    auto [p3,p4] = b;
    int c1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int c2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    if (c1 == 0 && c2 == 0) {
        if (p1 > p2) swap(p1, p2);
        if (p3 > p4) swap(p3, p4);
        return p3 <= p2 && p1 <= p4; // consider both case : a-c-b-d, c-a-d-b
    }
    return c1 <= 0 && c2 <= 0;
}

int dist2(point a, point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int hypot2(point p) {
    return p.x * p.x + p.y * p.y;
}

point vec(const line &a) {
    return a[1] - a[0];
}

int pointsegdist(point p, line l) { // returns square dist
    if ((p - l[0]) * vec(l) < 0) return dist2(l[0], p);
    if ((p - l[1]) * vec(l) > 0) return dist2(l[1], p);
    int a = l[1].y - l[0].y;
    int b = l[0].x - l[1].x;
    int c = -(l[0].x * a + l[0].y * b);

    return (a * p.x + b * p.y + c) * (a * p.x + b * p.y + c) / (a * a + b * b);
}

int segdist(line a, line b) {
    if (cross(a, b)) return 0;

    int res = min(pointsegdist(a[0], b), pointsegdist(a[1], b));
    res = min(res, min(pointsegdist(b[0], a), pointsegdist(b[1], a)));
    return res;
}

vector<point> convex_hull(vector<point> p) {
    if (p.size() == 1) return p;
    sort(all(p));
    point piv = p[0];
    // sort except pivot
    sort(p.begin() + 1, p.end(), [&](const point &a, const point &b) {
        if (a > piv ^ b > piv) {
            return a > piv;
        }
        if (ccw(piv, a, b) != 0) return ccw(piv, a, b) > 0;
        return hypot2(a - piv) < hypot2(b - piv);
    });
    vector<point> s;
    s.push_back(p[0]);
    s.push_back(p[1]);
    for (int i = 2; i < p.size(); i++) {
        while (s.size() >= 2) {
            point p1 = s[s.size() - 2];
            point p2 = s.back();
            s.pop_back();
            if (ccw(p1, p2, p[i]) > 0) {
                s.push_back(p2);
                break;
            }
        }
        s.push_back(p[i]);
    }
    return s;
}

pair<int, array<point, 2> > rotating_callipers(vector<point> p) { // return {dist^2, pair of two points}
    auto hull = convex_hull(p);
    int pt = 0;
    pair<int, array<point, 2> > res = {0, {p[0], p[0]}};
    for (int i = 0; i < hull.size(); i++) {
        while (pt + 1 < hull.size() &&
               ccw({0, 0}, hull[i + 1] - hull[i], hull[pt + 1] - hull[pt]) >= 0) {
            res = max(res, {dist2(hull[i], hull[pt]), {hull[i], hull[pt]}});
            pt++;
        }
        res = max(res, {dist2(hull[i], hull[pt]), {hull[i], hull[pt]}});
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<point> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    auto [p1,p2] = rotating_callipers(p).second;
    cout << p1.x << ' ' << p1.y << ' ' << p2.x << ' ' << p2.y << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<point> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    cout << setprecision(12) << sqrt(rotating_callipers(a).first);
}
