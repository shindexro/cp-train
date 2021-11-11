#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    ll n, k; cin >> n >> k;
    while (k--)
    {
        if (n % 200 == 0)
            n /= 200;
        else
            n = 1000 * n + 200;
    }
    cout << n;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

