#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    ll n, m, a; cin >> n >> m >> a;

    ll r = (n % a == 0) ? n / a : n / a + 1;
    ll c = (m % a == 0) ? m / a : m / a + 1;
    cout << r * c << "\n";

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

