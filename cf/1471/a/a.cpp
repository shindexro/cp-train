#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n, x; cin >> n >> x;
    ll total = 0;
    ll mx = 0;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        total += a;
        if (a % x == 0)
            mx += a/x;
        else
            mx += a/x + 1;
    }
    ll mn = (total % x == 0) ? total/x : total/x + 1;
    cout << mn << " " << mx << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
