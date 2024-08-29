#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int long long
using namespace std;
using pi = pair<int,int>;

pi twofive(int x) {
    int two = 2, five = 5;
    int twos = 0, fives = 0;
    while (two <= x) {
        twos += x / two;
        two *= 2;
    }
    while (five <= x) {
        fives += x / five;
        five *= 5;
    }
    return {twos, fives};
}

signed main() {
    int n, m;
    cin >> n >> m;
    pi ntf = twofive(n);
    pi mtf = twofive(m);
    pi nmtf = twofive(n - m);
    cout << min(ntf.first - mtf.first - nmtf.first, ntf.second - mtf.second - nmtf.second);
}
