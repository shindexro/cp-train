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

int candies(multiset<pair<int, int>> va, multiset<pair<int, int>> vb, int x)
{
    int cnt = 0;
    int n = va.size() + vb.size();
    for (int i = 0; i < n; i++) {
        auto& v = (i & 1) ? va : vb;
        auto it = v.lower_bound({ x + 1, -1 });
        if (it == v.begin())
            break;

        auto it2 = max_element(v.begin(), it, [&](auto a, auto b) {
            return a.second < b.second;
        });
        auto [h, m] = *it2;
        cnt++;
        x += m;
        v.erase(it2);
    }

    return cnt;
}

void solve(int tc)
{
    int n, x;
    cin >> n >> x;
    multiset<pair<int, int>> va, vb;
    for (int i = 0; i < n; i++) {
        int t, h, m;
        cin >> t >> h >> m;
        if (t)
            va.insert({ h, m });
        else
            vb.insert({ h, m });
    }

    int ans1 = candies(va, vb, x);
    int ans2 = candies(vb, va, x);
    cout << max(ans1, ans2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    for (int t = 1; t <= T; t++)
        solve(t);
}
