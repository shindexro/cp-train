#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n, m; cin >> n >> m;
    int arr[n], query[m];
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < m; i++) cin >> query[i];

    ll cyclePeak = arr[0];
    ll cycleSum = 0;
    for (int i = 0; i < n; i++)
    {
        cycleSum += arr[i];
        cyclePeak = max(cyclePeak, cycleSum);
    }



    for (int i = 0; i < m; i++)
    {
        ll t = query[i];
        if (cyclePeak < t && cycleSum <= 0)
        {
            cout << "-1 ";
        }
        else
        {
            ll ans = 0;
            ll cycles = (cycleSum <= 0 || t <= cyclePeak) ? 
                0 : ceil((double)(t - cyclePeak) / cycleSum);
            ans += cycles * n;
            t -= cycles * cycleSum;
            auto it = presum.lower_bound(t);
            ans += (*it).second;
            cout << ans << " ";
        }
    }
    cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
