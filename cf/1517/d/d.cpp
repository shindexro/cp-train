#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n,m,k; cin >> n >> m >> k;
    int hcost[n][m-1], vcost[n-1][m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m-1; j++)
            cin >> hcost[i][j];
    
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < m; j++)
            cin >> vcost[i][j];

    int dp[n][m][k + 1];
    for (int step = 0; step <= k; step += 2)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (step == 0)
                {
                    dp[i][j][step] = 0;
                    continue;
                }
                int cost = INT_MAX;
                if (i > 0)
                    cost = min(cost, 2*vcost[i-1][j] + dp[i-1][j][step-2]);
                if (j > 0)
                    cost = min(cost, 2*hcost[i][j-1] + dp[i][j-1][step-2]);
                if (i + 1 < n)
                    cost = min(cost, 2*vcost[i][j] + dp[i+1][j][step-2]);
                if (j + 1 < m)
                    cost = min(cost, 2*hcost[i][j] + dp[i][j+1][step-2]);
                dp[i][j][step] = cost;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int ans = (k % 2 == 0) ? dp[i][j][k] : -1;
            cout << ans << " ";
        }
        cout << "\n";
    }
    
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}
