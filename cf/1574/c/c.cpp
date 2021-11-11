#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve(int tc)
{
    int n, m;
    cin >> n;
    vector<ll> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];
    
    sort(all(a));
    ll total=accumulate(all(a), 0ll);
    
    cin >> m;
    for (int drag = 0; drag<m; drag++) {
        ll x, y;
        cin>>x>>y;

        auto it = lower_bound(all(a), x);
        ll ans = LLONG_MAX;

        if (it != a.end()) {
            ans = min(ans, max(0ll, x-*it) + max(0ll, y-(total-*it)));
        }
        if (it != a.begin()) {
            --it;
            ans = min(ans, max(0ll, x-*it) + max(0ll, y-(total-*it)));
        }

        cout<<ans<<"\n";
    }


}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++)
        solve(t);
}
