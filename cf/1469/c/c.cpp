#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n, k; cin >> n >> k;
    int h[n];
    for (int i = 0; i < n; i++) cin >> h[i];

    int mn = h[0], mx = h[0];
    for (int i = 1; i < n; i++)
    {
        mx = min(mx + k - 1, h[i] + k - 1);
        mn = max(mn + 1 - k, h[i]);
        if (mn > mx)
        {
            cout << "NO\n";
            return;
        }
    }
    if (mn == h[n-1])
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
