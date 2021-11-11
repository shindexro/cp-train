#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    ll x; cin >> x;
    double M = cbrt(x);
    for (ll a = 1; a < M; a++)
    {
        ll a3 = a * a * a;
        ll b3 = x - a3;
        ll b = cbrt(b3);
        if (b * b * b == b3)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
