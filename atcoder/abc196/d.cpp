#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dfs(vector<vector<bool>> &occ, int h, int w, int i, int j, int tiles)
{
    if (tiles == 0)
        return 1;
    if (i == h)
        return 0;
    if (j == w)
        return dfs(occ, h, w, i+1, 0, tiles);
    if (occ[i][j])
        return dfs(occ, h, w, i, j+1, tiles);

    int res = 0;
    if (j+1 < w && !occ[i][j+1])
    {
        occ[i][j] = occ[i][j+1] = true;
        res += dfs(occ, h, w, i, j+1, tiles-1);
        occ[i][j] = occ[i][j+1] = false;
    }
    if (i+1 < h && !occ[i+1][j])
    {
        occ[i][j] = occ[i+1][j] = true;
        res += dfs(occ, h, w, i, j+1, tiles-1);
        occ[i][j] = occ[i+1][j] = false;
    }
    res += dfs(occ, h, w, i, j+1, tiles);
    return res;
}


void solve(int _t)
{
    int h, w; cin >> h >> w;
    int a, b; cin >> a >> b;

    vector<vector<bool>> occ(h, vector<bool>(w));
    int ans = dfs(occ, h, w, 0, 0, a);
    cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

