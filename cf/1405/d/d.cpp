#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int farest_node(map<int, set<int>>& edge, int u)
{
    queue<pii> q;
    set<int> vis;
    q.push({ u, 0 });
    vis.insert(u);

    int ans = u, mx_dist = 0;
    while (q.size()) {
        auto [cur, d] = q.front();
        q.pop();

        if (d > mx_dist) {
            ans = cur;
            mx_dist = d;
        }

        for (int nxt : edge[cur]) {
            if (vis.find(nxt) == vis.end()) {
                vis.insert(nxt);
                q.push({ nxt, d + 1 });
            }
        }
    }
    return ans;
}

int dist(map<int, set<int>>& edge, int u, int v)
{
    queue<pii> q;
    set<int> vis;
    q.push({ u, 0 });
    vis.insert(u);

    while (q.size()) {
        auto [cur, d] = q.front();
        q.pop();

        if (cur == v) {
            return d;
        }

        for (int nxt : edge[cur]) {
            if (vis.find(nxt) == vis.end()) {
                vis.insert(nxt);
                q.push({ nxt, d + 1 });
            }
        }
    }
    return -1;
}

int diameter(map<int, set<int>>& edge)
{
    int u = farest_node(edge, 1);
    int v = farest_node(edge, u);
    return dist(edge, u, v);
}

void solve(int tc)
{
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    map<int, set<int>> edge;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].insert(v);
        edge[v].insert(u);
    }

    if (db <= da * 2 || dist(edge, a, b) <= da || diameter(edge) <= 2 * da) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve(t);
    }
}
