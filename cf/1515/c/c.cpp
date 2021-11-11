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

typedef pair<int, int> pii;

void solve(int tc)
{
    int n, m, x;
    cin >> n >> m >> x;

    vector<pii> v(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v[i] = { a, i };
    }

    sort(v.rbegin(), v.rend());
    priority_queue<pii, vector<pii>, greater<pii>> towers;
    for (int i = 1; i <= m; i++)
        towers.push({ 0, i });

    int mx = 0;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        auto [h, t] = towers.top();
        debug(i, h, t);
        towers.pop();
        h += v[i].first;
        towers.push({ h, t });
        ans[v[i].second] = t;
        mx = max(mx, h);
    }

    if (mx - towers.top().first <= x) {
        cout << "YES\n";
        for (int a : ans)
            cout << a << " ";
        cout << "\n";
    } else
        cout << "NO\n";
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
