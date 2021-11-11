#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
typedef pair<int, int> pii;

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V>& x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T& x)
{
    int f = 0;
    cerr << '{';
    for (auto& i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

#define EPS 1e-12

long double expect(long double c, long double m, long double p, long double v, int cnt)
{
    if (c < EPS)
        c = 0;
    if (m < EPS)
        m = 0;

    long double res = p * cnt;

    if (0 < c && c <= v) {
        res += c * expect(0, (m > 0) ? c / 2 + m : 0, (m > 0) ? c / 2 + p : c + p, v, cnt + 1);
    } else if (c > v) {
        res += c * expect(c - v, (m > 0) ? v / 2 + m : 0, (m > 0) ? v / 2 + p : v + p, v, cnt + 1);
    }

    if (0 < m && m <= v) {
        res += m * expect((c > 0) ? m / 2 + c : 0, 0, (c > 0) ? m / 2 + p : m + p, v, cnt + 1);
    } else if (m > v) {
        res += m * expect((c > 0) ? v / 2 + c : 0, m - v, (c > 0) ? v / 2 + p : v + p, v, cnt + 1);
    }

    return res;
}

void solve(int tc)
{
    long double c, m, p, v;
    cin >> c >> m >> p >> v;

    cout << fixed << setprecision(16) << expect(c, m, p, v, 1) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
        solve(t);
}
