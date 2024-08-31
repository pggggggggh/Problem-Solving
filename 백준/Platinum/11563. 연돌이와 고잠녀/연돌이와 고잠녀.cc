#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int,int>;

struct point {
    double x, y;

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

    double operator*(const point &b) const { // dot
        return x * b.x + y * b.y;
    }

    double operator/(const point &b) const { // cross
        return x * b.y - y * b.x;
    }
};

typedef array<point, 2> line;


point vec(const line &a) {
    return a[1] - a[0];
}

int ccw(point a, point b, point c) {
    point va = {b.x - a.x, b.y - a.y};
    point vb = {c.x - b.x, c.y - b.y};
    double cross = va / vb;
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
        return p3 <= p2 && p1 <= p4; // a c b d, c a d b의 경우를 모두 처리 가능
    }
    return c1 <= 0 && c2 <= 0;
}

double dist(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double pointsegdist(point p, line l) {
    if ((p - l[0]) * vec(l) < 0) return dist(l[0], p);
    if ((p - l[1]) * vec(l) > 0) return dist(l[1], p);
    double a = l[1].y - l[0].y;
    double b = l[0].x - l[1].x;
    double c = -(l[0].x * a + l[0].y * b);

    return abs((a * p.x + b * p.y + c) / sqrt(a * a + b * b));
}

double segdist(line a, line b) {
    if (cross(a, b)) return 0;

    double ret = min(pointsegdist(a[0], b), pointsegdist(a[1], b));
    ret = min(ret, min(pointsegdist(b[0], a), pointsegdist(b[1], a)));
    return ret;
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<line> a(n), b(m);
    for (int i = 0; i < n; i++) {
        double sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        a[i][0] = {sx, sy};
        a[i][1] = {ex, ey};
    }
    for (int i = 0; i < m; i++) {
        double sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        b[i][0] = {sx, sy};
        b[i][1] = {ex, ey};
    }

    double res = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res = min(res, segdist(a[i], b[j]));
        }
    }
    cout.precision(12);
    cout << fixed << res;
}
