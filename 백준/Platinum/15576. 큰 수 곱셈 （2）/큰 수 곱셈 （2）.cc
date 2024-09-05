#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define MOD 20070713
using pi = pair<int, int>;

typedef complex<double> cpx;
const double PI = acos(-1);

void fft(vector<cpx> &f, bool inv = false) {
    int n = f.size();
    int j = 0;
    for (int i = 1; i < n; i++) {
        int bit = n / 2;
        while (j >= bit) {
            j -= bit;
            bit /= 2;
        }
        j += bit;
        if (i < j) swap(f[i], f[j]);
    }

    vector<cpx> root(n / 2);
    double ang = 2 * PI / n;
    if (inv) ang *= -1;

    for (int i = 0; i < n / 2; i++) root[i] = cpx(cos(ang * i), sin(ang * i));
    for (int i = 2; i <= n; i *= 2) {
        int step = n / i;
        for (int j = 0; j < n; j += i) {
            for (int k = 0; k < i / 2; k++) {
                cpx u = f[j | k];
                cpx v = f[j | k | i / 2] * root[step * k];
                f[j | k] = u + v;
                f[j | k | i / 2] = u - v;
            }
        }
    }
    if (inv) for (int i = 0; i < n; i++) f[i] /= n;
}

vector<int> mul(const vector<int> &_a, const vector<int> &_b) {
    vector<cpx> a, b;
    for (auto i: _a) a.push_back(cpx(i, 0));
    for (auto i: _b) b.push_back(cpx(i, 0));

    int n = 1;
    while (n < a.size() + b.size()) n *= 2;
    a.resize(n);
    b.resize(n);

    cpx w(cos(2 * PI / n), sin(2 * PI / n));
    fft(a);
    fft(b);
    for (int i = 0; i < n; i++) a[i] *= b[i];

    vector<int> ret(n);
    fft(a, 1);
    for (int i = 0; i < n; i++) ret[i] = round(a[i].real());
    while (ret.size() > 1 && !ret.back()) ret.pop_back();

    return ret;
}

string sa, sb;
vector<int> a, b;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> sa >> sb;
    for (int i = 0; i < sa.size(); i++) a.push_back(sa[i] - '0');
    for (int i = 0; i < sb.size(); i++) b.push_back(sb[i] - '0');
    vector<int> c = mul(a, b);

    int olim = 0;
    int now = 0;
    vector<int> jari(a.size() + b.size() - 1);
    for (int i = c.size() - 1; i > 0; i--) {
        jari[i] += c[i];
        jari[i - 1] += jari[i] / 10;
        jari[i] %= 10;
    }
    jari[0] += c[0];
    for (auto &x: jari) cout << x;
}
