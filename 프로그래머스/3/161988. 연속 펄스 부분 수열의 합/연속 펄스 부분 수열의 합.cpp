#include <string>
#include <vector>
#define ll long long

using namespace std;

ll solution(vector<int> sequence) {
    int n = sequence.size();
    for (int i=0;i<n;i++) {
        if (i&1) sequence[i] *= -1;
    }
    ll mn = 0;
    ll psum = 0;
    ll ans = 0;
    for (int i=0;i<n;i++) {
        psum += sequence[i];
        ans = max(ans,psum-mn);
        mn = min(psum,mn);
    }
    for (int i=0;i<n;i++) {
        sequence[i] *= -1;
    }
    mn = 0;
    psum = 0;
    for (int i=0;i<n;i++) {
        psum += sequence[i];
        ans = max(ans,psum-mn);
        mn = min(psum,mn);
    }
    
    return ans;
}