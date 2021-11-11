#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve(int tc)
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = n + 1;
    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;
        int cnt = 0;
        int l = 0, r = n - 1;
        bool ok = true;
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else if (s[l] == c) {
                cnt++;
                l++;
            } else if (s[r] == c) {
                cnt++;
                r--;
            } else {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans = min(ans, cnt);
        }
    }

    if (ans <= n) {
        cout << ans << "\n";
    } else {
        cout << -1 << "\n";
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
