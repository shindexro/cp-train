#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf = 1e9 + 48763;

void solve(int _t)
{
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    vector<int> idx;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
            idx.push_back(i);
    }
    int cnt = idx.size();

    vector<vector<int>> dp(n, vector<int>(cnt+1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= cnt; j++)
        {
            if (i == 0)
                dp[i][j] = (a[i] == 0 && j == 1) ? idx[0] : inf;
            else if (a[i] == 1)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = min(dp[i-1][j-1] + abs(idx[j-1] - i), dp[i-1][j]);
        }
    }

//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j <= cnt; j++)
//            cout << dp[i][j] << " ";
//        cout << "\n";
//    }
    cout << dp[n-1][cnt] << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}
