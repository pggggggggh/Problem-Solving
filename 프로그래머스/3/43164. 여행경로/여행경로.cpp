#include <bits/stdc++.h>
using namespace std;

map<string,multiset<string>> adj;
vector<string> ans;

void dfs(string u) {
    while (!adj[u].empty()) {
        auto it = adj[u].begin();
        string v = *it;
        adj[u].erase(it);
        dfs(v);
    }
    ans.push_back(u);
}

vector<string> solution(vector<vector<string>> tickets) {
    for (auto &x:tickets) {
        adj[x[0]].insert(x[1]);
    }
    dfs("ICN");
    reverse(ans.begin(),ans.end());
    return ans;
}