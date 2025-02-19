#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> stk,ans(n);
    for (int i=n-1;i>=0;i--) {
        while (!stk.empty() && prices[stk.back()] >= prices[i]) {
            stk.pop_back();
        }
        if (stk.empty()) ans[i] = n-1-i;
        else ans[i] = stk.back()-i;
        stk.push_back(i);
    }
    return ans;
}