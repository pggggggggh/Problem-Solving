#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    vector<int> stk;
    for (int i=0;i<s.size();i++) {
        if (s[i]=='(') stk.push_back(i);
        else {
            if (stk.empty()) return false;
            stk.pop_back();
        }
    }

    return stk.empty();
}