#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define MOD 998244353
#define INF 987654321987654321LL
#define all(x) x.begin(),x.end()
#define fi(x) for(i=0;i<x;i++)
#define fi1(x) for(i=1;i<=x;i++)
#define fj(x) for(j=0;j<x;j++)
#define fj1(x) for(j=1;j<=x;j++)
#define fk(x) for(k=0;k<x;k++)
#define fk1(x) for(k=1;k<=x;k++)
#define fastio() {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pq priority_queue
#define vvi vector<vector<int> >
#define X first
#define Y second
#define endl '\n'
#define int long long
#define pbds tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

using namespace __gnu_pbds;
using namespace std;
typedef pair<int,int> P;

int n, p;
string s;

vector<string> tokenize(string s, char x) {
    int i;
    int now = 0;
    vector<string> ret;

    int past = -1;

    for (i = 0; i < s.size(); i++) {
        if (s[i] == '(') now++;
        if (s[i] == ')') now--;

        if (s[i] == x && now == 0) {
            string t = s.substr(past + 1, i - past - 1);
            ret.pb(t);
            past = i;
        }
    }
    string t = s.substr(past + 1, i - past - 1);
    ret.pb(t);
    return ret;
}

string dnc(string x) {
    int i, j;

    stack<int> st;
    int flag = 0;
    fi(x.size()) {
        if (x[i] == '(') st.push(i);
        if (x[i] == ')') {
            int past = st.top();
            st.pop();
            if (i == x.size() - 1 && past == 0) flag = 1;
        }
    }
    if (flag) return "(" + dnc(x.substr(1, x.length() - 2)) + ")";
    vector<string> vs = tokenize(x, '+');

    string ret = "";
    if (vs.size() == 1) {
        vector<string> vs2 = tokenize(x, '*');
        if (vs2.size() == 1) return x;
        fi(vs2.size()-1) ret += "(";
        fi(vs2.size()) {
            if (i) ret += "*";
            ret += dnc(vs2[i]);
            if (i) ret += ")";
        }

        return ret;
    }

    fi(vs.size()-1) ret += "(";
    for (i = 0; i < vs.size(); i++) {
        if (i) ret += "+";
        ret += dnc(vs[i]);
        if (i) ret += ")";
    }

    return ret;
}

signed main() {
    int i, j;

    cin >> n >> p;
    cin >> s;

    string ans = dnc(s);
    cout << ans.size() << endl;
    cout << ans;
}
