#include <bits/stdc++.h>
#define ll long long
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    if (n >= rocks.size()) return distance;
    int answer = 0;
    ll lo = 1, hi = 1e18;
    sort(rocks.begin(),rocks.end());
    while (lo+1 < hi) {
        ll mid = lo+hi>>1;
        int passed = 0, cur = 0;
        for (int i=0;i<rocks.size();i++) {
            if (distance-rocks[i] < mid) passed++;
            else if (rocks[i] - cur < mid) passed++;
            else cur = rocks[i];
        }
        cout<<mid<<' '<<passed<<'\n';
        if (passed <= n) lo = mid;
        else hi = mid;
    }
    return lo;
}