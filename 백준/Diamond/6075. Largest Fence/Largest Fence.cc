#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int,int>;

struct point {
    int x, y;

    point operator-(const point &p) const {
        return {x - p.x, y - p.y};
    }

    bool operator<(const point &p) const {
        return tie(x, y) < tie(p.x, p.y);
    }

    bool operator>(const point &p) const {
        return tie(x, y) > tie(p.x, p.y);
    }
};

int ccw(point a, point b, point c) {
    int cross = a.x * b.y + b.x * c.y + c.x * a.y
                - (b.x * a.y + c.x * b.y + a.x * c.y);
    if (cross < 0) return -1;
    return cross > 0;
}

int n;
int dp[255][255];
vector<point> sorted;
point p0;

int recur(int i1, int i2) {
    int &res = dp[i1][i2];
    if (res != -1e18) return res;

    point p1 = sorted[i1], p2 = sorted[i2];
    if (ccw(p1, p2, p0) > 0) {
        // 끝낼 수 있음
        res = 0;
    } else {
        res = -1e9;
    }
    for (int i = i2 + 1; i < sorted.size(); i++) {
        if (ccw(p1, p2, sorted[i]) > 0) res = max(res, recur(i2, i) + 1);
    }
    // cout << i1 << ' ' << i2 << ':' << res << '\n';
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<point> P(n);
    for (int i = 0; i < n; i++) cin >> P[i].x >> P[i].y;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        sorted.clear();
        p0 = P[i];
        sorted.push_back(p0);
        for (int j = 0; j < n; j++) {
            if (j != i && P[j] > p0) sorted.push_back(P[j]);
        }
        sort(sorted.begin() + 1, sorted.end(), [&](const point &a, const point &b) -> int {
            if (a < p0 ^ b < p0) return a < p0;
            return ccw(p0, a, b) > 0;
        });
        // for (int j = 0; j < sorted.size(); j++) cout << sorted[j].x << ' ' << sorted[j].y << '\n';
        for (int j = 0; j < n; j++) for (int k = 0; k < n; k++) dp[j][k] = -1e18;
        int res = 0;
        for (int j = 1; j < sorted.size(); j++) {
            res = max(res, recur(0, j));
        }
        ans = max(ans, res + 2);
    }
    cout << ans;
}
