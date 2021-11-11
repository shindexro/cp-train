#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dfs(vector<int> color, vector<vector<bool>> adj, int node, set<int> visited)
{
    int n = adj.size();
    set<int> neighbors;
    for (int i = 0; i < n; i++)
    {
        if (adj[node][i] && visited.find(node) == visited.end())
        {
            neighbors.insert(i);
            visited.insert(i);
        }
    }

    ll res = 0;
    for (int neighbor : neighbors)
    {
        for (int c = 1; c <= 3; c++)
        {
            if (c != color[node])
            {
                color[neighbor] = c;
                res += dfs(color, adj, neighbor, visited);
            }
        }
    }
    return res;
}

void solve(int _t)
{
    int n, m; cin >> n >> m;
    vector<vector<bool>> adj(n, vector<bool>(n));
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a][b] = adj[b][a] = true;
    }

    set<int> visited;
    vector<int> color(n);
    ll ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (visited.find(i) == visited.end())
        {
            color[i] = 1;
            ans *= dfs(color, adj, i, visited);
        }
    }

    cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

