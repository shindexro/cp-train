#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n; cin >> n;
    ll c[n], a[n], b[n];
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    ll dp[n];
    dp[0] = 0;
    ll ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == b[i])
            dp[i] = c[i] + 1;
        else
            dp[i] = max(dp[i-1] + c[i] - (abs(a[i] - b[i]) - 1),
                        abs(a[i] - b[i]) + 1 + c[i]);

        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
