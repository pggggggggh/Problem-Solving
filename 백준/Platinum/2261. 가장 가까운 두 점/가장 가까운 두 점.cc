#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int,int>;

int n;
vector<pi> P;

int dist(const pi &x, const pi &y) {
    return (x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second);
}

int dnc(int l, int r) {
    if (r - l + 1 <= 3) {
        int res = 1e18;
        for (int i = l; i < r; i++) {
            for (int j = i + 1; j <= r; j++) {
                res = min(res, dist(P[i], P[j]));
            }
        }
        return res;
    }
    int mid = l + r >> 1;
    int d = min(dnc(l, mid), dnc(mid + 1, r));
    vector<pi> band;
    for (int i = l; i <= r; i++) {
        if (abs(P[i].first - P[mid].first) * abs(P[i].first - P[mid].first) < d) band.push_back(P[i]);
    }
    sort(all(band), [&](const pi &x, const pi &y) {
        return x.second < y.second;
    });
    int res = d;
    for (int i = 0; i < band.size(); i++) {
        for (int j = i + 1; j < band.size(); j++) {
            if ((band[j].second - band[i].second) * (band[j].second - band[i].second) > d) break;
            res = min(res, dist(band[i], band[j]));
        }
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    P.resize(n);
    for (int i = 0; i < n; i++) cin >> P[i].first >> P[i].second;
    sort(all(P), [&](const pi &x, const pi &y) {
        return x.first < y.first;
    });
    cout << dnc(0, n - 1);
}
