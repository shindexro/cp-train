#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    ll r, b, d; cin >> r >> b >> d;
    
    ll p = min(r, b);
    ll diff = abs(r - b);
    if (p * d < diff)
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
