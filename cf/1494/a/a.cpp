#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

bool ok(string& s, int sa, int sb, int sc)
{
    int cnt = 0;
    for (char c : s) {
        if (c == 'A')
            cnt += sa;
        else if (c == 'B')
            cnt += sb;
        else if (c == 'C')
            cnt += sc;

        if (cnt < 0)
            return false;
    }
    if (cnt != 0)
        return false;

    return true;
}

void solve(int tc)
{
    string s;
    cin >> s;

    for (int i = -1; i <= 1; i += 2) {
        for (int j = -1; j <= 1; j += 2) {
            for (int k = -1; k <= 1; k += 2) {
                if (ok(s, i, j, k)) {
                    cout << "YES\n";
                    return;
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
