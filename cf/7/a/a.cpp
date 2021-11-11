#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    vector<string> board(8);
    for (int i = 0; i < 8; i++)
        cin >> board[i];

    int hline = 0, vline = 0;
    for (int i = 0; i < 8; i++)
    {
        if (count(board[i].begin(), board[i].end(), 'B') == 8)
            hline++;
    }
    for (int j = 0; j < 8; j++)
    {
        int black = 0;
        for (int i = 0; i < 8; i++)
        {
            if (board[i][j] == 'B')
                black++;
        }
        if (black == 8)
            vline++;
    }

    if (vline == 8 && hline == 8)
        cout << 8;
    else
        cout << vline + hline;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}
