#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve(int tc)
{
    int n, k;
    cin >> n >> k;

    if (k == 1) {
        cout << "YES\n";
        for (int i = 1; i <= n; i++)
            cout << i << "\n";
        return;
    }

    if (n % 2 == 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < k; j++) {
                cout << i + j * n << " ";
            }
            cout << "\n";
        }
    }
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
