#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dfs(vector<ll> v, ll xorSum, int idx)
{
    if (idx == v.size())
        return xorSum;

    ll res = -1;
    for (int i = 1; idx + i <= v.size(); i++)
    {
        ll orSum = 0;
        for (int j = 0; j < i; j++)
            orSum |= v[idx+j];
        ll alt = dfs(v, xorSum ^ orSum, idx + i);
        if (res == -1 || alt < res)
            res = alt;
    }
    return res;
}

void solve(int _t)
{
    int n; cin >> n;
    vector<ll> v(n);
    for (ll &a : v)
        cin >> a;

    ll ans = dfs(v, 0, 0);
    cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

