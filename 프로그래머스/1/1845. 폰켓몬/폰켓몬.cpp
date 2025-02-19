#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    set<int> st;
    for (auto &x:nums) st.insert(x);
    return min(nums.size()/2,st.size());
}