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

int dist2(point a, point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int hypot2(point p) {
    return p.x * p.x + p.y * p.y;
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

int n, t;
vector<point> p, d;

int f(int x) {
    vector<point> p2 = p;
    for (int i = 0; i < n; i++) p2[i] = {p2[i].x + x * d[i].x, p2[i].y + x * d[i].y};
    return rotating_callipers(p2).first;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;
    p.resize(n);
    d.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y >> d[i].x >> d[i].y;
    }
    int res = -1;
    for (int i = 0; i <= t; i++) {
        if (res == -1 || f(i) < f(res)) res = i;
    }
    cout << res << '\n' << f(res);
}
