#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int sum = 0;
    for (int x : a)
        sum += x;

    ll ans = 0;
    for (int x : a)
    {
        ans += 1ll * (n-1) * x * x;
        ans -= 1ll * x * (sum - x);
    }
    cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

