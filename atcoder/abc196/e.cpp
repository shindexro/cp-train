#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    ll lo = -1e16;
    ll hi = 1e16;
    ll sum = 0;
    while (n--)
    {
        ll a, t; cin >> a >> t;
        if (t == 1)
        {
            lo += a;
            hi += a;
            sum += a;
        }
        else if (t == 2)
        {
            lo = max(lo, a);
            hi = max(hi, a);
        }
        else
        {
            hi = min(hi, a);
            lo = min(lo, a);
        }
    }

    int q; cin >> q;
    while (q--)
    {
        ll x; cin >> x;
        cout << max(lo, min(hi, x + sum)) << "\n";
    }

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

