#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string a;
    cin >> n >> a;

    vector<int> psum(n);
    vector<vector<int>> psumpos(2 * n + 1);
    int cur = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] == '(') cur++;
        else cur--;
        psum[i] = cur;
        psumpos[cur + n].push_back(i);
    }

    vector<int> sa(n), rnk(n);
    iota(sa.begin(), sa.end(), 0);
    for (int i = 0; i < n; ++i) rnk[i] = a[i];

    int d = 1;
    auto cmp = [&](int i, int j) {
        if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];
        int ri = (i + d < n ? rnk[i + d] : -1);
        int rj = (j + d < n ? rnk[j + d] : -1);
        return ri < rj;
    };

    vector<int> tmp(n);
    while (true) {
        sort(sa.begin(), sa.end(), cmp);
        tmp[0] = 0;
        for (int i = 1; i < n; ++i) {
            tmp[i] = tmp[i - 1] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
        }
        for (int i = 0; i < n; ++i) {
            rnk[sa[i]] = tmp[i];
        }
        if (tmp[n - 1] == n - 1) break;
        d <<= 1;
    }

    vector<int> lcp(n);
    int k = 0;
    vector<int> rank(n);
    for (int i = 0; i < n; ++i) {
        rank[sa[i]] = i;
    }

    for (int i = 0; i < n; ++i) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = sa[rank[i] + 1];
        while (i + k < n && j + k < n && a[i + k] == a[j + k]) ++k;
        lcp[rank[i] + 1] = k;
        if (k > 0) --k;
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int p = (sa[i] == 0) ? 0 : psum[sa[i] - 1];
        int idx = lower_bound(psumpos[p - 1 + n].begin(), psumpos[p - 1 + n].end(), sa[i]) - psumpos[p - 1 + n].begin();

        int hi;
        if (idx >= psumpos[p - 1 + n].size()) hi = n - 1;
        else hi = psumpos[p - 1 + n][idx] - 1;

        int lo = sa[i] + lcp[i];
        if (hi < lo) continue;

        int left = lower_bound(psumpos[p + n].begin(), psumpos[p + n].end(), lo) - psumpos[p + n].begin();
        int right = upper_bound(psumpos[p + n].begin(), psumpos[p + n].end(), hi) - psumpos[p + n].begin();

        ans += right - left;
    }

    cout << ans << '\n';
    return 0;
}
