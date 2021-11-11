#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;

int tick_size(vector<string>& canvas, int n, int m, int i, int j)
{
    int size = 0;
    while (i - size >= 0 && j - size >= 0 && j + size < m
        && canvas[i - size][j - size] == '*' && canvas[i - size][j + size] == '*') {
        size++;
    }
    return size - 1;
}

void canvas_erase(vector<string>& canvas, int n, int m, int i, int j, int sz)
{
    canvas[i][j] = '.';
    while (sz) {
        canvas[i - sz][j - sz] = canvas[i - sz][j + sz] = '.';
        sz--;
    }
}

void solve(int tc)
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> canvas(n);
    for (string& s : canvas)
        cin >> s;

    vector<string> replicate(n);
    for (int i = 0; i < n; i++)
        replicate[i] = canvas[i];

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int sz = tick_size(canvas, n, m, i, j);
            if (sz >= k) {
                canvas_erase(replicate, n, m, i, j, sz);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (replicate[i][j] == '*') {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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
