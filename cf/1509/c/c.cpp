#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    ll dp[n][n];
    for (int len = 1; len <= n; len++)
    {
        for (int i = 0; i < n; i++)
        {
            int j = i + len - 1;
            if (j >= n)
                continue;

            if (i == j)
                dp[i][j] = 0;
            else
                dp[i][j] = arr[j] - arr[i] + min(dp[i][j-1], dp[i+1][j]);
        }
    }

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << dp[i][j] << " ";
//         }
//         cout << "\n";
//     }
    
    cout << dp[0][n-1] << "\n";    
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

