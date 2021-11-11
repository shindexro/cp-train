#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve(int tc)
{
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    vector<int> last(m + 1);
    last[m] = n;
    for (int i = m - 1; i >= 0; i--) {
        last[i] = s.find_last_of(t[i], last[i + 1] - 1);
    }

    int ans = 0;
    for (int i = 0, j = 0; i < n, j < m - 1; i++) {
        if (s[i] == t[j]) {
            ans = max(ans, last[j + 1] - i);
            j++;
        }
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
