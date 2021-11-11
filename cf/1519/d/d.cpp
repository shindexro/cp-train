#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n; cin >> n;
    ll a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    ll total = 0;
    for (int i = 0; i < n; i++)
        total += a[i] * b[i];

    // state space: (length, startIndex)
    ll dp[n+1][n];
    ll ans = 0;
    for (int len = 0; len <= n; len++)
    {
        for (int i = 0; i < n; i++)
        {
            int j = i + len - 1;
            if (j >= n)
            {
                dp[len][i] = 0;
            }
            else if (len <= 1)
            {
                dp[len][i] = total;
            }
            else
            {
                dp[len][i] = dp[len-2][i+1] - a[i]*b[i] - a[j]*b[j]
                                            + a[i]*b[j] + a[j]*b[i];
            }
            ans = max(ans, dp[len][i]);
        }
    }

    cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}
