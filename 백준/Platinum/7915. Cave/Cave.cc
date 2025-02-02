#include <bits/stdc++.h>
#define REP(i,a,b) for (auto i = (a); i <= (b); ++i)
using namespace std;

const int N = 3e6+3;
int n, sub[N], cnt[N], par[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    REP(i,1,n-1) cin >> par[i+1];
    for (int i = n; i >= 1; --i) {
        sub[par[i]] += (++sub[i]);
        cnt[sub[i]]++;
    }
    for (int i = n; i >= 1; --i) {
        if (n%i == 0) {
            int x = 0;
            for (int j = i; j <= n; j += i) x += cnt[j];
            if (x == n/i) cout << n/i << ' ';
        }
    }
}