#include <bits/stdc++.h>
#define MOD 998244353LL
#define INF 987654321987654321LL
#define v(x) x.begin(),x.end()
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

using namespace std;
typedef pair<int, int> P;

int n,q;
int a[100005];
vector<int> bucket[400];

signed main()
{
    fastio();
    vector<int> nums;
    int i,j;

    cin>>n;
    int sq = sqrt(n);

    fi1(n) {
        cin>>a[i];
        nums.pb(a[i]);
    }

    cin>>q;
    vector<vector<int>> queries(q, vector<int>(4));
    fi(q) {
        cin>>queries[i][0];
        if (queries[i][0] == 1) {
            cin >> queries[i][1] >> queries[i][2] >> queries[i][3];
            nums.pb(queries[i][3]);
        }
        else {
            cin >> queries[i][1] >> queries[i][2];
            nums.pb(queries[i][2]);
        }
    }

    sort(v(nums));
    nums.erase(unique(v(nums)), nums.end());

    fi1(n) {
        a[i] = lower_bound(v(nums), a[i]) - nums.begin();
        bucket[i/sq].pb(a[i]);
    }
    for (i=0;i<=n/sq;i++) {
        sort(v(bucket[i]));
    }

    fi(q) {
        if (queries[i][0] == 1) {
            int k = lower_bound(v(nums), queries[i][3]) - nums.begin();
            int l = queries[i][1];
            int r = queries[i][2];

            int ans = 0;
            while (l%sq != 0 && l<=r) {
                if (a[l] > k) ans++;
                l++;
            }
            while ((r+1)%sq != 0 && l<=r) {
                if (a[r] > k) ans++;
                r--;
            }
            while (l<=r) {
                int tmp = bucket[l / sq].end() - upper_bound(v(bucket[l / sq]), k);
                ans += tmp;
                l += sq;
            }

            cout<<ans<<endl;
        }
        else {
            int val = lower_bound(v(nums), queries[i][2]) - nums.begin();
            int idx = queries[i][1];

            bucket[idx / sq].erase(lower_bound(v(bucket[idx / sq]), a[idx]));
            bucket[idx / sq].insert(lower_bound(v(bucket[idx / sq]), val), val);

            a[idx] = val;
        }
    }
}