#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int delta[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

ll bfs(vector<vector<ll>> a, ll w)
{
    int n = a.size();
    int m = a[0].size();
    queue<tuple<int,int,int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m));
    q.push({0, 0, 0});
    visited[0][0] = true;

    while (q.size())
    {
        auto t = q.front();
        q.pop();
        int x, y, s;
        tie(x, y, s) = t;
        if (x == n-1 && y == m-1)
            return s * w;
        
        for (int i = 0; i < 4; i++)
        {
            int x2 = x + delta[i][0];
            int y2 = y + delta[i][1];
            if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < m &&
                    a[x2][y2] != -1 &&
                    !visited[x2][y2])
            {
                visited[x2][y2] = true;
                q.push({x2,y2,s+1});
            }
        }
    }
    return -1;
}
ll bfs_portal(vector<vector<ll>> a, int r, int c, ll w)
{
    int n = a.size();
    int m = a[0].size();
    ll cost = -1;
    queue<tuple<int,int,int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m));
    q.push({r, c, 0});
    visited[0][0] = true;

    while (q.size())
    {
        auto t = q.front();
        q.pop();
        int x, y, s;
        tie(x, y, s) = t;
        if (a[x][y] > 0)
        {
            ll alt = a[x][y] + s * w;
            cost = (cost == -1) ? alt : min(cost, alt);
        }
        
        for (int i = 0; i < 4; i++)
        {
            int x2 = x + delta[i][0];
            int y2 = y + delta[i][1];
            if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < m &&
                    a[x2][y2] != -1 &&
                    !visited[x2][y2])
            {
                visited[x2][y2] = true;
                q.push({x2,y2,s+1});
            }
        }
    }
    return cost;
}

void solve(int _t)
{
    int n, m, w; cin >> n >> m >> w;
    vector<vector<ll>> arr(n, vector<ll>(m));
    for (int a = 0; a < n; a++)
        for (int b = 0; b < m; b++)
            cin >> arr[a][b];

    ll start2portal = bfs_portal(arr, 0, 0, w);
    ll end2portal = bfs_portal(arr, n-1, m-1, w);
    ll start2end = bfs(arr, w);

    if ((start2portal == -1 || end2portal == -1) && start2end == -1)
        cout << "-1\n";
    else if (start2end == -1)
        cout << start2portal + end2portal << "\n";
    else if (start2portal == -1 || end2portal == -1)
        cout << start2end << "\n";
    else
        cout << min(start2portal + end2portal, start2end) << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}
