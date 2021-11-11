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

    auto inc = [&](int i, int j) {
        return (board[i][j] == '+') == ((i + j) % 2 == 1);
    };

    vector<vector<int>> dp(h, vector<int>(w));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (i == 0 && j == 0)
                continue;
            if (inc(i, j))
                dp[i][j]++;
            else
                dp[i][j]--;
        }
    }
    for (int i = h-1; i >= 0; i--)
    {
        for (int j = w-1; j >= 0; j--)
        {
            bool taka = (i + j) % 2 == 0;
            if (i == h-1 && j == w-1)
                continue;
            else if (i == h-1)
                dp[i][j] += dp[i][j+1];
            else if (j == w-1)
                dp[i][j] += dp[i+1][j];
            else if (taka)
                dp[i][j] += max(dp[i][j+1], dp[i+1][j]);
            else
                dp[i][j] += min(dp[i][j+1], dp[i+1][j]);
        }
    }
    
    int score = dp[0][0];
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

