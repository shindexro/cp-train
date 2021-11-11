#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n; cin >> n;
    int as[n], bs[n];
    for (int i = 0; i < n; i++) cin >> as[i];
    for (int i = 0; i < n; i++) cin >> bs[i];

    int ord[n];
    for (int i = 0; i < n; i++) ord[i] = i;
    sort(ord, ord+n, [&](int a, int b){ return as[a] < as[b]; });

    ll selfTime = 0;
    for (int b : bs)
        selfTime += b;

    ll ans = selfTime;
    for (int i = 0; i < n; i++)
    {
        int idx = ord[i];
        ll deliTime = as[idx];
        selfTime -= bs[idx];
        ll totalTime = max(deliTime, selfTime);
        ans = min(ans, totalTime);
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
