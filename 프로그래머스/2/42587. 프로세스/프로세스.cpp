#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> priorities, int location) {
    priority_queue<int> pq;
    int n = priorities.size();
    for (int i=0;i<n;i++) pq.push(priorities[i]);
    int cnt = 0;
    vector<int> done(n);
    for (int i=0;;i=(i+1)%n) {
        if (done[i]) continue;
        if (priorities[i] != pq.top()) continue;
        pq.pop();
        done[i] = 1;
        cnt++;
        if (i == location) return cnt;
    }
}