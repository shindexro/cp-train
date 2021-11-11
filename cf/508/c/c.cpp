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
    int m, t, r;
    cin >> m >> t >> r;
    vector<int> v(m);
    for (int& a : v)
        cin >> a;

    if (r > t) {
        cout << "-1\n";
        return;
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int a : v) {
        pq.push({ a + t + 1, 1 });
    }

    int ans = 0;
    int light = 0;
    while (pq.size()) {
        auto [ts, cat] = pq.top();
        pq.pop();
        debug(pq.size(), ts, cat);

        if (cat == 0) {
            light--;
        } else if (cat == 1 && light < r) {
            int need = r - light;
            for (int i = ts - 1; need > 0; i--, need--) {
                pq.push({ i + 1 + t, 0 });
                ans++;
                light++;
            }
        }
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
