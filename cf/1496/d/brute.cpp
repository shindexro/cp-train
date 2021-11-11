#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

bool xwin(vector<int>& v, int cx, int cy)
{
    int n = v.size();
    for (int dx = -1; dx <= 1; dx += 2) {
        bool win = true;
        for (int dy = -1; dy <= 1; dy += 2) {
            int x = cx, y = cy;
            bool xturn = true;
            while (true) {
                if (xturn) {
                    if (x + dx < 0 || x + dx >= n || v[x] < v[x + dx] || x + dx == y) {
                        win = false;
                        break;
                    }
                    x += dx;
                } else {
                    if (y + dy < 0 || y + dy >= n || v[y] > v[y + dy] || y + dy == x) {
                        break;
                    }
                    y += dy;
                }
                xturn = !xturn;
            }
        }
        if (win)
            return true;
    }
    return false;
}

void solve(int tc)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        bool win = true;
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;

            if (!xwin(v, i, j)) {
                win = false;
                break;
            }
        }
        if (win)
            ans++;
    }

    cout << ans << "\n";
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
