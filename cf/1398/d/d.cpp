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
    int r, g, b;
    cin >> r >> g >> b;
    vector<int> rs(r), gs(g), bs(b);
    for (int& a : rs)
        cin >> a;
    for (int& a : gs)
        cin >> a;
    for (int& a : bs)
        cin >> a;

    sort(rs.rbegin(), rs.rend());
    sort(gs.rbegin(), gs.rend());
    sort(bs.rbegin(), bs.rend());
    debug(rs);
    debug(gs);
    debug(bs);

    int ans = 0;
    vector<vector<vector<int>>> dp(r + 1, vector<vector<int>>(g + 1, vector<int>(b + 1)));
    for (int i = 0; i <= r; i++) {
        for (int j = 0; j <= g; j++) {
            for (int k = 0; k <= b; k++) {
                if (i > 0 && j > 0)
                    dp[i][j][k] = max(dp[i][j][k],
                        dp[i - 1][j - 1][k] + rs[i - 1] * gs[j - 1]);
                if (i > 0 && k > 0)
                    dp[i][j][k] = max(dp[i][j][k],
                        dp[i - 1][j][k - 1] + rs[i - 1] * bs[k - 1]);
                if (k > 0 && j > 0)
                    dp[i][j][k] = max(dp[i][j][k],
                        dp[i][j - 1][k - 1] + gs[j - 1] * bs[k - 1]);
                ans = max(ans, dp[i][j][k]);
                debug(i, j, k, dp[i][j][k]);
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
