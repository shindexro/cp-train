#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> dp(n);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int p = max(0, v[i] - 1 - dp[i]);
        int nextIdx = min(n - 1, i + v[i]);
        for (int j = i + 2; j <= nextIdx; j++)
            dp[j]++;
        int extra = p - (v[i] - 1);
        if (i + 1 < n)
            dp[i + 1] += extra;
        ans += p;
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
