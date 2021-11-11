#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int) 1e9 + 7)

void solve(int _t)
{
    int p, k; cin >> p >> k;

    ll ans = 1;
    if (k == 0)
    {
        for (int i = 0; i < p-1; i++)
        {
            ans *= p;
            ans %= MOD;
        }
        cout << ans << "\n";
        return;
    }        

    vector<bool> used(p);
    used[0] = true;
    for (int i = 0; i < p; i++)
    {
        if (!used[i])
        {
            ans *= p;
            ans %= MOD;
            ll cur = i;
            do
            {
                used[cur] = true;
                cur *= k;
                cur %= p;
            } while (cur != i);
        }
    }
    if (k == 1)
    {
        ans *= p;
        ans %= MOD;
    }
    cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}
