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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<vector<int>> levels(n);

    vector<bool> seen(n + 1);
    queue<pair<int, int>> q;
    q.push({ 1, 0 });
    seen[1] = true;
    while (q.size()) {
        auto [u, depth] = q.front();
        q.pop();
        levels[depth].push_back(u);

        for (int v : edges[u]) {
            if (seen[v])
                continue;
            q.push({ v, depth + 1 });
            seen[v] = true;
        }
    }
    debug(levels);

    int cnt = 0;
    for (int i = 0; i < n; i += 2)
        cnt += levels[i].size();

    cout << ((cnt <= n / 2) ? cnt : n - cnt) << "\n";
    for (int i = (cnt <= n / 2) ? 0 : 1; i < n; i += 2) {
        for (int u : levels[i])
            cout << u << " ";
    }
    cout << "\n";
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
