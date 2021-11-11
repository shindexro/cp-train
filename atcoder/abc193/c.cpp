#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    ll n; cin >> n;
    set<ll> seen;
    for (ll i = 2; i * i <= n; i++)
    {
        ll cur = i * i;
        while (cur <= n)
        {
            seen.insert(cur);
            cur *= i;
        }
    }
    cout << n - seen.size();
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

