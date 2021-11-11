#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    ll r, x, y; cin >> r >> x >> y;
    ll d2 = x*x + y*y;
    ll r2 = r*r;

    ll n2 = d2/r2;
    ll n = sqrt(n2);

    int ans = 0;
    if (d2 < r2)
        ans = 2;
    else if (n*n == n2 && n2*r2 == d2)
        ans = n;
    else
        ans = n + 1;

    cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

