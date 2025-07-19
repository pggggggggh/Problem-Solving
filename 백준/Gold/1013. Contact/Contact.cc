
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <functional>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <sstream>
#define INF 987654321
#define int long long
#define MOD c

using namespace std;

int t;
string a;

signed main()
{
    int i,j;

    cin >> t;
    while (t--) {
        cin >> a;
        int n = a.size();
        int flag = 1;
        for (int now=0;now<n;) {
            //cout << now << "\n";
            if (a[now] == '0') {
                if (a[now+1] == '1') now += 2;
                else {
                    flag = 0;
                    break;
                }
            } else {
                if (a[now+1] == '0' && a[now+2] == '0') {
                    now++;
                    while (a[now] == '0') now++;
                    if (a[now] != '1') {
                        flag = 0;
                        break;
                    }
                    while (a[now] == '1') now++;
                    if (now < n && a[now-2] == '1' && a[now-1] == '1' && a[now] == '0' && a[now+1] == '0') now-=1;
                } else {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
}