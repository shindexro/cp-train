#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
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

void solve(int tc)
{
    int n, m, k;
    cin >> n >> m >> k;
    map<int, int> x, y;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        x[a] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        y[a] = 0;
    }

    map<int, map<int, int>> xy, yx;

    ll ans = 0;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        auto [x1, xcnt] = *x.lower_bound(a);
        auto [y1, ycnt] = *y.lower_bound(b);
        if (a != x1) {
            ans += x[x1] - xy[x1][b];
            x[x1]++;
            xy[x1][b]++;
        }
        if (b != y1) {
            ans += y[y1] - yx[y1][a];
            y[y1]++;
            yx[y1][a]++;
        }
    }

    cout << ans << "\n";
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
