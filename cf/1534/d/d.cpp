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

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2>& pair) const
    {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

void solve(int tc)
{
    int n;
    cin >> n;

    cout << "? 1\n";
    vector<vector<int>> dist(n);
    unordered_set<pii, pair_hash> edges;

    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        dist[d].push_back(i);
    }

    vector<int> dp(n);
    dp[1] = dist[1].size();
    dp[2] = dist[2].size();
    for (int i = 3; i < n; i++) {
        dp[i] = dist[i].size() + min(dp[i - 1], dp[i - 2]);
    }

    int cur = (dp[n - 1] < dp[n - 2]) ? n - 1 : n - 2;
    while (cur > 0) {
        for (int a : dist[cur]) {
            cout << "? " << a + 1 << "\n";
            for (int i = 0; i < n; i++) {
                int d;
                cin >> d;
                if (d == 1)
                    edges.insert({ min(i, a), max(i, a) });
            }
        }
        cur = (dp[cur - 1] + dist[cur].size() == dp[cur]) ? cur - 1 : cur - 2;
    }
    for (int a : dist[1])
        edges.insert({ 0, a });

    cout << "!\n";
    for (auto [u, v] : edges) {
        cout << u + 1 << " " << v + 1 << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int T = 1;
    for (int t = 1; t <= T; t++)
        solve(t);
}
