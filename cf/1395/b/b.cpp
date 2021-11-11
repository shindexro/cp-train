#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void move(int x, int y)
{
    cout << x << " " << y << "\n";
}

void solve(int tc)
{
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;

    move(sx, sy);
    move(1, sy);
    for (int i = 1; i <= n; i++) {
        for (int j = (i & 1) ? 1 : m; 1 <= j && j <= m; j = (i & 1) ? j + 1 : j - 1) {
            if ((i == sx && j == sy) || (i == 1 && j == sy)) {
                continue;
            }
            move(i, j);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve(t);
    }
}
