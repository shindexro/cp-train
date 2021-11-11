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

    int x = 1, y = 1;
    int dir = 0;
    vector<vector<bool>> seen(n + 1, vector<bool>(m + 1));
    for (int i = 0; i < m * n / 2; i++) {
        int x2 = n - x + 1, y2 = m - y + 1;
        cout << x << " " << y << "\n";
        cout << x2 << " " << y2 << "\n";
        debug(i, x, y, x2, y2, dir);
        seen[x][y] = seen[x2][y2] = true;

        if (dir == 0 && (x + 1 > n || seen[x + 1][y]))
            dir = 1;
        if (dir == 1 && (y + 1 > m || seen[x][y + 1]))
            dir = 2;
        if (dir == 2 && (x - 1 < 1 || seen[x - 1][y]))
            dir = 3;
        if (dir == 3 && (y - 1 < 1 || seen[x][y - 1]))
            dir = 0;

        switch (dir) {
        case 0:
            x++;
            break;
        case 1:
            y++;
            break;
        case 2:
            x--;
            break;
        case 3:
            y--;
            break;
        }
    }

    if ((m * n) & 1)
        cout << x << " " << y << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    for (int t = 1; t <= T; t++)
        solve(t);
}
