#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;

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
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> lsock(n + 1), rsock(n + 1);
    for (int i = 0; i < l; i++) {
        int c;
        cin >> c;
        lsock[c]++;
    }
    for (int i = 0; i < r; i++) {
        int c;
        cin >> c;
        rsock[c]++;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int pairs = min(lsock[i], rsock[i]);
        lsock[i] -= pairs;
        rsock[i] -= pairs;
        l -= pairs;
        r -= pairs;
    }
    if (l < r) {
        swap(l, r);
        swap(lsock, rsock);
    }
    for (int i = 1; i <= n; i++) {
        int pairs = min(lsock[i] / 2, (l - r) / 2);
        lsock[i] -= pairs * 2;
        l -= pairs * 2;
        ans += pairs;
    }
    debug(l, lsock, r, rsock);
    ans += l;
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
