#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;

signed main() {
    int a, b, c;
    while (1) {
        cin >> a >> b >> c;
        if (a == 0) break;
        int flag = 0;
        if (a * a + b * b == c * c) flag = 1;
        if (a * a + c * c == b * b) flag = 1;
        if (b * b + c * c == a * a) flag = 1;
        cout << (flag ? "right" : "wrong") << '\n';
    }
}
