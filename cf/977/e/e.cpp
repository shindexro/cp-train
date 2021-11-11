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

    vector<vector<int>> neigh(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        neigh[u].push_back(v);
        neigh[v].push_back(u);
    }

    unordered_set<int> seen;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (seen.find(i) != seen.end())
            continue;
        seen.insert(i);

        if (neigh[i].size() != 2)
            continue;

        int fst = i;
        int last = i;
        int cur = neigh[i][0];
        while (neigh[cur].size() == 2 && cur != fst) {
            if (seen.find(cur) != seen.end())
                break;
            seen.insert(cur);
            int u = neigh[cur][0];
            int v = neigh[cur][1];
            debug(fst, cur, u, v, last);
            if (u != last) {
                last = cur;
                cur = u;
            } else {
                last = cur;
                cur = v;
            }
        }
        if (cur == fst)
            ans++;
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
