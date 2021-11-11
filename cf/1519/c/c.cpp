#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n; cin >> n;
    int uni[n], skill[n];
    for (int i = 0; i < n; i++) cin >> uni[i];
    for (int i = 0; i < n; i++) cin >> skill[i];

    vector<vector<int>> bst(n, vector<int>());
    for (int i = 0; i < n; i++)
        bst[uni[i]-1].push_back(skill[i]);
    for (int i = 0; i < n; i++)
        sort(bst[i].rbegin(), bst[i].rend());
    
    vector<vector<ll>> presum(n, vector<ll>(1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int a : bst[i])
        {
            presum[i].push_back(presum[i].back() + a);
        }
    }

    vector<ll> ans(n);
    for (int i = 0; i < n; i++)
    {
        for (int k = 1; k <= bst[i].size(); k++)
        {
            ans[k-1] += presum[i][bst[i].size() - bst[i].size() % k];
        }
    }

    for (int a : ans)
        cout << a << " ";
    cout << "\n";

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
