#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int,int>;

struct point {
    int x, y;
} a[10005];

int n;

signed main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
    double res = 0;
    for (int i = 1; i < n - 1; i++) {
        double cross = a[0].x * a[i].y + a[i].x * a[i + 1].y + a[i + 1].x * a[0].y
                       - a[0].y * a[i].x - a[i].y * a[i + 1].x - a[i + 1].y * a[0].x;
        res += cross / 2.0;
    }
    cout.precision(1);
    cout << fixed << abs(res);
}
