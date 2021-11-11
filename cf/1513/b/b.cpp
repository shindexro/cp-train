#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    ll n; cin >> n;
    ll mod = 1e9 + 7;
    map<ll,ll> freq;
    ll sum = INT_MAX;
    for (int i=0; i < n; i++) {
        int a; cin >> a;
        freq[a]++;
        sum &= a;
    }

    if (freq[sum] >= 2) {
        ll ans = (freq[sum] * (freq[sum]-1)) % mod;
        for (int i=n-2; i>=2; i--)
            ans = (ans * i) % mod;
        cout << ans << "\n";
    } else {
        cout << 0 << "\n";
    }
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}

