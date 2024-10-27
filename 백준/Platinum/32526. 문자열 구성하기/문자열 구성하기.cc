#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

void solve()
{
   int n, k;
   cin >> n >> k;
   if (k == 0) {
      if (n == 2) {
         cout << "No\n";
         return;
      }
      cout << "Yes\n";
      for (int i = 0; i < n; i++) cout << "swoon"[i % 5];
      return;
   }
   if (k == 1) {
      cout << "Yes\n";
      for (int i = 0; i < n - 1; i++) cout << 'a';
      cout << 'b';
      return;
   }
   if (k == n - 1) {
      cout << "Yes\n";
      for (int i = 0; i < n; i++) cout << 'a';
      return;
   }
   if (n % k == 0) { // abb로 채우기
      cout << "Yes\n";
      int len = n / k;
      string s = "a";
      for (int i = 1; i < len; i++) s += "b";
      for (int i = 0; i < n / len; i++) cout << s;
      return;
   }

   if (n % (k + 1) != 0) { // aba나 abba .. 로 채우기
      cout << "No\n";
      return;
   }
   int palin = n / (k + 1);
   if (palin == 2) {
      cout << "No\n";
      return;
   }
   // palin > 3
   cout << "Yes\n";
   string s = "";
   for (int i = 0; i < (palin - 1) / 2; i++) s += 'o';
   if (palin % 2) s += 'w';
   else s += "ww";
   for (int i = 0; i < (palin - 1) / 2; i++) s += 'o';
   for (int i = 0; i < k + 1; i++) cout << s;
}

signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   solve();
}