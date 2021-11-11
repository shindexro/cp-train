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
    int x0, y0;
    cin >> x0 >> y0;
    x0--;
    y0--;
    int left, right;
    cin >> left >> right;

    vector<string> maze(n);
    for (string& s : maze)
        cin >> s;

    queue<tuple<int, int, int, int>> q;
    vector<vector<tuple<int, int, bool>>> seen(n, vector<tuple<int, int, bool>>(m));
    q.push({ x0, y0, left, right });
    seen[x0][y0] = { left, right, true };

    vector<pair<int, int>> dirs = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
    while (q.size()) {
        auto [x, y, l, r] = q.front();
        q.pop();

        for (auto [dx, dy] : dirs) {
            if ((dy == -1 && !l) || (dy == 1 && !r))
                continue;

            int x2 = x + dx, y2 = y + dy;
            int l2 = (dy == -1) ? l - 1 : l;
            int r2 = (dy == 1) ? r - 1 : r;
            if (0 <= x2 && x2 < n && 0 <= y2 && y2 < m
                && maze[x2][y2] == '.'
                && (!get<2>(seen[x2][y2])
                    || l2 > get<0>(seen[x2][y2])
                    || r2 > get<1>(seen[x2][y2]))) {

                debug(x, y, x2, y2, l2, r2);

                q.push({ x2, y2, l2, r2 });
                seen[x2][y2] = { l2, r2, true };
            }
        }
    }

    int ans = 0;
    for (auto& row : seen) {
        for (auto [l, r, ok] : row) {
            if (ok)
                ans++;
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
