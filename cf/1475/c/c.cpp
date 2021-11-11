#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int a, b, k; cin >> a >> b >> k;
    map<int,int> boyFreq, girlFreq;
    for (int i = 0; i < k; i++)
    {
        int n; cin >> n;
        boyFreq[n]++;
    }
    for (int i = 0; i < k; i++)
    {
        int n; cin >> n;
        girlFreq[n]++;
    }

    ll ans = 1ll * k * (k-1) / 2;
    for (auto [n,f] : boyFreq)
    {
        ans -= 1ll * f * (f-1) / 2;
    }
    for (auto [n,f] : girlFreq)
    {
        ans -= 1ll * f * (f-1) / 2;
    }
    cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
