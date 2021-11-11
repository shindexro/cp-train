#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n, c; cin >> n >> c;
    vector<ll> earn(n), edu(n-1);
    for (int i=0; i < n; i++) cin >> earn[i];
    for (int i=0; i < n-1; i++) cin >> edu[i];

    vector<ll> daysToLevel(n), saving(n);
    for (int i=1; i < n; i++) {
        ll need = max(0LL, edu[i-1] - saving[i-1]);
        ll earnDays = (need % earn[i-1] == 0) ? need / earn[i-1] : need / earn[i-1] + 1;
        daysToLevel[i] = daysToLevel[i-1] + earnDays + 1;
        saving[i] = earnDays * earn[i-1] + saving[i-1] - edu[i-1];
    }

    ll ans = LLONG_MAX;
    for (int i=0; i < n; i++) {
        ll need = max(0LL, c - saving[i]);
        ll earnDays = (need % earn[i] == 0) ? need / earn[i] : need / earn[i] + 1;
        ans = min(ans, daysToLevel[i] + earnDays);
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

