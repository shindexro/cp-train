#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    vector<ll> a(n);
    for (ll &x : a)
        cin >> x;

    ll ans = a[0] * n + a[1] * n;
    ll vmin = a[0], hmin = a[1];
    ll vbase = a[0], hbase = a[1];
    ll vseg = 1, hseg = 1;
    for (int i = 2; i < n; i++)
    {
        if (i % 2 == 0)
        {
            vseg++;
            vmin = min(vmin, a[i]);
            vbase += a[i];
        }
        else
        {
            hseg++;
            hmin = min(hmin, a[i]);
            hbase += a[i];
        }

        ans = min(ans, vbase + hbase + vmin * (n-vseg) + hmin * (n-hseg));
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
