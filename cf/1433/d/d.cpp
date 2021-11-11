#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> g1, g2;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == v[0])
            g1.push_back(i);
        else
            g2.push_back(i);
    }

    if (g2.size() == 0)
    {
        cout << "NO\n";
        return;
    }

    vector<pair<int,int>> ans;
    for (int i : g2)
        ans.push_back({0, i});
    for (int i = 1; i < g1.size(); i++)
        ans.push_back({g2[0], g1[i]});

    cout << "YES\n";
    for (auto [i,j] : ans)
    {
        cout << i+1 << " " << j+1 << "\n";
    }
    
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
