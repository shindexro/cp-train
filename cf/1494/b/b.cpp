#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve(int tc)
{
    int cnt[4];
    int n;
    cin >> n >> cnt[0] >> cnt[1] >> cnt[2] >> cnt[3];

    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            for (int c = 0; c <= 1; c++) {
                for (int d = 0; d <= 1; d++) {
                    if (cnt[0] - a - b >= 0 && cnt[0] - a - b <= n - 2
                        && cnt[1] - b - c >= 0 && cnt[1] - b - c <= n - 2
                        && cnt[2] - c - d >= 0 && cnt[2] - c - d <= n - 2
                        && cnt[3] - d - a >= 0 && cnt[3] - d - a <= n - 2) {
                        cout << "YES\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve(t);
    }
}
