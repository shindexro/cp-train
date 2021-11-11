#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve(int tc)
{
    int h, w; cin >> h >> w;
    vector<string> board(h);
    for (int i = 0; i < h; i++)
        cin >> board[i];

    vector<vector<int>> dp(h, vector<int>(w));
    for (int i = 1; i < h; i++)
    {
        if ((board[i][0] == '+') == (i % 2 == 1))
            dp[i][0] = 1 + dp[i-1][0];
        else
            dp[i][0] = -1 + dp[i-1][0];
    }
    for (int i = 1; i < w; i++)
    {
        if ((board[0][i] == '+') == (i % 2 == 1))
            dp[0][i] = 1 + dp[0][i-1];
        else
            dp[0][i] = -1 + dp[0][i-1];
    }

    for (int i = 1; i < h; i++)
    {
        for (int j = 1; j < w; j++)
        {
            bool taka = (i + j) % 2 == 1;
            if (board[i][j] == '+' && taka)
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
            else if (board[i][j] == '+' && !taka)
                dp[i][j] = -1 + max(dp[i-1][j], dp[i][j-1]);
            else if (board[i][j] == '-' && taka)
                dp[i][j] = -1 + min(dp[i-1][j], dp[i][j-1]);
            else
                dp[i][j] = 1 + max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int score = dp.back().back();
    if (score > 0)
        cout << "Takahashi\n";
    else if (score < 0)
        cout << "Aoki\n";
    else
        cout << "Draw\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++)
        solve(t);
}


