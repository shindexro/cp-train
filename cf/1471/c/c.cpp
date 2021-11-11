#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n, m; cin >> n >> m;
    vector<int> k(n), prices(m);
    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
        k[i]--;
    }
    for (int i = 0; i < m; i++) cin >> prices[i];

    sort(k.rbegin(), k.rend());

    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += prices[k[i]];
    for (int i = 0; i < n; i++)
    {
        if (i < k[i])
        {
            ans -= prices[k[i]];
            ans += prices[i];
        }
        else
            break;
    }
    cout << ans << "\n";

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
