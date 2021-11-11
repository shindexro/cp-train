#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    ll n; cin >> n;
    ll ans = 0;
    ll base = 999;
    while (base < n)
    {
        ans += n - base;
        base = base * 1000 + 999;
    }
    cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

