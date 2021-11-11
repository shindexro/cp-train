#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> v[i][j];

    for (int i = 0; i < n; i++)
        sort(v[i].rbegin(), v[i].rend());

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m/2; j++)
        {
            ans += v[i][j];
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
