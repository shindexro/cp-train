#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve(int tc)
{
    int x, y;
    cin >> x >> y;

    ll ans = 0;
    for (int a = 1; a * (a + 2) <= x; a++) {
        ans += max(0, min((x / a) - a - 1, y - a));
    }
    cout << ans << "\n";
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
