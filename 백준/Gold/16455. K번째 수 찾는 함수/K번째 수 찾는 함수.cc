#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
using pi = pair<int, int>;

signed kth(vector<signed> &a, signed k) {
  random_shuffle(all(a));
  nth_element(a.begin(), a.begin() + k - 1, a.end());
  return a[k - 1];
}