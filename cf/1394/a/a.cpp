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

void solve(int tc)
{
    int n, d, m;
    cin >> n >> d >> m;
    vector<int> safe, dang;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a > m)
            dang.push_back(a);
        else
            safe.push_back(a);
    }

    sort(rall(safe));
    sort(rall(dang));
    debug(safe, dang);

    ll ans = 0;
    int dang_idx = 0;
    int remain = n;
    if (dang.size()) {
        remain--;
        ans += dang[0];
        dang_idx++;
    }
    while (remain > d && dang_idx < dang.size()) {
        ans += dang[dang_idx++];
        remain -= d + 1;
    }

    ll cur = ans;
    int safe_idx = 0;
    while ((remain || dang_idx) && safe_idx < safe.size()) {
        debug(safe_idx, dang_idx);
        if (remain) {
            cur += safe[safe_idx++];
            remain--;
        } else {
            cur -= dang[--dang_idx];
            remain += dang_idx ? d + 1 : 1;
        }
        ans = max(ans, cur);
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    for (int t = 1; t <= T; t++)
        solve(t);
}
