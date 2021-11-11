#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int h, w, x, y; cin >> h >> w >> x >> y;
    x--;
    y--;
    vector<vector<bool>> obs(h, vector<bool>(w));
    for (int i = 0; i < h; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < w; j++)
        {
            if (s[j] == '#')
                obs[i][j] = true;
        }
    }

    vector<pair<int,int>> d;
    d.push_back({0, -1});
    d.push_back({0, 1});
    d.push_back({-1, 0});
    d.push_back({1, 0});

    int ans = 0;
    for (auto p : d)
    {
        int curx = x, cury = y;
        while (curx >= 0 && curx < h &&
                cury >= 0 && cury < w &&
                !obs[curx][cury])
        {
            ans++;
            curx += p.first;
            cury += p.second;
        }
    }
    ans -= 3;
    cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

