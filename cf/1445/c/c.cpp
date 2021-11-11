#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))

void solve(int _t)
{
    ll p, q; cin >> p >> q;


    vector<ll> qfactors;
    for (int i = 1; i * i <= q; i++)
    {
        if (q % i == 0)
        {
            qfactors.push_back(i);
            if (q / i != i)
                qfactors.push_back(q / i);
        }
    }

    ll ans = 1;
    for (ll f : qfactors)
    {
        if (f == 1) continue;

        ll x = p;
        while (x % q == 0)
            x /= f;
        ans = max(ans, x);
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
