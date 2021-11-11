#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    ll a, b; cin >> a >> b;
    if (a > b)
        swap(a, b);
    ll d = b - a;

    int ans = 0;
    ll minLCM = lcm(a, b);
    for (int x = 1; x * x <= d; x++)
    {
        if (d % x != 0)
            continue;

        int k = x - a % x;
        ll LCM = lcm(a + k, b + k);
        if (LCM < minLCM)
        {
            ans = k;
            minLCM = LCM;
        }
        
        int y = d / x;
        k = y - a % y;
        LCM = lcm(a + k, b + k);
        if (LCM < minLCM)
        {
            ans = k;
            minLCM = LCM;
        }
    }

    cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}
