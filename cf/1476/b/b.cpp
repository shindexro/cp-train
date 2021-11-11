#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll ans = 0;
    ll pre = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] * 100 > k * pre)
        {
            ll oldpre = pre;
            pre = ceil(1.0 * a[i] * 100 / k);
            ans += pre - oldpre;
        }
        pre += a[i];
    }

    cout << ans << "\n";

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
