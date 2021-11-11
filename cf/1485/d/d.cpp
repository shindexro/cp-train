#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

#define N 502

void solve(int tc)
{
    int n, m;
    cin >> n >> m;
    int mat[N][N];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    int magic = 1;
    for (int i = 1; i <= 16; i++) {
        magic = lcm(magic, i);
    }

    int ans[N][N];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i + j) & 1) {
                ans[i][j] = magic;
            } else {
                int a = mat[i][j];
                ans[i][j] = magic + a * a * a * a;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
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
