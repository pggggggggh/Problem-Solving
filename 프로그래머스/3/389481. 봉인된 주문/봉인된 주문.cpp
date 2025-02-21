#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll stonum(string x) {
    ll ret = 0, cur = 1;
    for (int i=1;i<x.length();i++) {
        cur *= 26;
        ret += cur;
    }
    cur = 1;
    for (int i=x.length()-1;i>=0;i--) {
        ret += (x[i]-'a')*cur;
        cur *= 26;
    }
    return ret;
}

string numtos(ll x) {
    ll sz = 1, cur = 26;
    while (x >= cur) {
        x -= cur;
        cur *= 26;
        sz++;
    }
    cur /= 26;
    string ret = "";
    while (cur) {
        ret += 'a'+(x/cur);
        x %= cur;
        cur /= 26;
    }
    return ret;
}

string solution(ll n, vector<string> bans) {
    vector<ll> banl;
    for (auto &s:bans) banl.push_back(stonum(s));
    sort(banl.begin(),banl.end());
    
    ll lo = -1, hi = 1e18;
    n--;
    while (lo+1 < hi) {
        ll mid = lo+hi>>1;
        if (mid-(upper_bound(banl.begin(),banl.end(),mid)-banl.begin()) >= n) hi = mid;
        else lo = mid;
    }
    return numtos(hi);
}