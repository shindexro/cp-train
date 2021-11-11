#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;

pair<int,int> fstBlack(vector<vector<bool>> &black)
{
    for (int i = 0; i < black.size(); i++)
        for (int j = 0; j < black[i].size(); j++)
            if (black[i][j])
                return {i, j};
}

void solve(int tc)
{
    int h, w; cin >> h >> w;
    vector<vector<bool>> black(2*h, vector<bool>(2*w));
    for (int i = 0; i < h; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < w; j++)
            black[2*i][2*j] = black[2*i+1][2*j]
                = black[2*i][2*j+1] = black[2*i+1][2*j+1]
                = (s[j] == '#');
    }

    auto [i, j] = fstBlack(black);
    vector<pair<int,int>> dir;
    dir.push_back({0, 1});
    dir.push_back({-1, 0});
    dir.push_back({0, -1});
    dir.push_back({1, 0});
    int curdir = 0;
    int x = i, y = j;
    int ans = 1;
    do {
        cerr << x << " " << y << "\n";
        auto rdir = dir[(curdir+1)%4];
        auto fdir = dir[curdir];
        auto ldir = dir[(curdir+3)%4];
        auto bdir = dir[(curdir+2)%4];
        if (black[x+rdir.first][y+rdir.second])
        {
            ans++;
            curdir = (curdir+1)%4;
            x += rdir.first;
            y += rdir.second;
        }
        else if (black[x+fdir.first][y+fdir.second])
        {
            x += fdir.first;
            y += fdir.second;
        }
        else if (black[x+ldir.first][y+ldir.second])
        {
            ans++;
            curdir = (curdir+3)%4;
            x += ldir.first;
            y += ldir.second;
        }
        else if (black[x+bdir.first][y+bdir.second])
        {
            ans += 2;
            curdir = (curdir+2)%4;
            x += bdir.first;
            y += bdir.second;
        }
    } while (i != x || j != y);

    cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++)
        solve(t);
}

