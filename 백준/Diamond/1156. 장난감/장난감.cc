#include <bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
using pi = pair<int, int>;

int d, n1, n2, c1, c2, tc;
int a[100005];

int go(int bought) {
    int res = bought * tc; // bought x
    deque<pi> dq1, dq2, dq3;
    for (int i = 1; i <= d; i++) {
        while (!dq3.empty() && dq3.front().first <= i - n2) {
            dq2.push_back(dq3.front());
            dq3.pop_front();
        }
        while (!dq2.empty() && dq2.front().first <= i - n1) {
            dq1.push_back(dq2.front());
            dq2.pop_front();
        }
        int needed = a[i];
        int usebought = min(bought, needed);
        needed -= usebought;
        bought -= usebought;
        while (needed && !dq1.empty()) {
            int touse = min(needed, dq1.back().second);
            needed -= touse;
            dq1.back().second -= touse;
            res += touse * c1;
            if (dq1.back().second == 0) dq1.pop_back();
        }
        while (needed && !dq2.empty()) {
            int touse = min(needed, dq2.back().second);
            needed -= touse;
            dq2.back().second -= touse;
            res += touse * c2;
            if (dq2.back().second == 0) dq2.pop_back();
        }
        if (needed > 0) return -1;
        dq3.push_back({i, a[i]});
    }
    return res;
}

signed main() {
    cin >> d >> n1 >> n2 >> c1 >> c2 >> tc;
    int sum = 0;
    for (int i = 1; i <= d; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (n1 < n2) {
        swap(n1, n2);
        swap(c1, c2);
    }
    int lo = 0, hi = sum;
    while (lo + 5 <= hi) {
        int p = (2 * lo + hi) / 3;
        int q = (lo + 2 * hi) / 3;
        int resp = go(p), resq = go(q);
        if (resq == -1) lo = q;
        else if (resp == -1) lo = p;
        else if (resp <= resq) hi = q;
        else lo = p;;
    }
    int res = 1e18;
    for (int i = lo; i <= hi; i++) {
        if (go(i) == -1) continue;
        res = min(res, go(i));
    }
    cout << res;
}
