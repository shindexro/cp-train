#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n, m, k; cin >> n >> m >> k;

    ll cost = (m-1) + (n-1)*m;

    if (k == cost)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
