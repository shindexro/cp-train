#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    int k = 2, m = 3;
    map<int,int> freq;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        freq[a]++;
    }

    ll ans = 0;
    for (auto cur = freq.begin(); cur != freq.end(); cur++)
    {
        auto [elem,f] = *cur;
        auto end = freq.upper_bound(elem + k);
        ll c = 0;
        for (auto it = cur; it != end; it++)
        {
            auto [a,b] = *it;
            c += b;
        }
        ll r = max(0LL, c-f);
        if (c > 2)
            ans += c * (c-1) * (c-2) / 6 - r * (r-1) * (r-2) / 6;
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
