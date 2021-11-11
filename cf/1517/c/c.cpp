#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n; cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        cin >> board[i][i];
        int curR = i, curC = i;
        for (int count = 1; count < board[i][i]; count++)
        {
            if (curC > 0 && board[curR][curC-1] == 0)
                curC--;
            else
                curR++;
            board[curR][curC] = board[i][i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 0)
                break;
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

}

int main()
{
	// ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}
