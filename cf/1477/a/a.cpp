#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    ll n, k; cin >> n >> k;
    vector<ll> v(n);
    for (ll &a : v)
        cin >> a;
    
    // to remove the contriant on the diophantine eqt
    // i.e. not allowing solution with all even/odd numbers
    // subtract x0 from all xs and k to ensure a zero is on the board
    // this is possible becuase 2(a-x0) - (b-x0) = (2a-b) - x0
    ll g = v[1] - v[0];
    for (int i = 1; i < n; i++)
    {
        g = gcd(g, v[i] - v[0]);
    }
    k -= v[0];
    if (k % g == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
