#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD (int)(1e9 + 7);

const int N = 10, M = 2e5+10;
vector<vector<ll>> dp(N, vector<ll>(M));

void buildDP()
{
    for (int i = 0; i < 10; i++) dp[i][0] = 1;

    for (int j = 1; j < M; j++) {
        for (int i = 0; i < 9; i++) {
            dp[i][j] = dp[i+1][j-1];
        }
        dp[9][j] = (dp[1][j-1] + dp[0][j-1]) % MOD;
    }
}

void solve(int _t)
{
    int n, m; cin >> n >> m;
    ll ans = 0;
    while (n) {
        ans = (ans + dp[n%10][m]) % MOD;
        n /= 10;
    }
    cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
    buildDP();
	for (int t = 1; t <= T; t++) solve(t);
}

