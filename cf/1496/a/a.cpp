#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve(int tc)
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    if (2 * k >= n) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < k; i++) {
        if (s[i] != s[n - 1 - i]) {
            cout << "NO\n";
            return;
        };
    }
    cout << "YES\n";
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
