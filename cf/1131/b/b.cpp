#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    ll ans = 0;
    int threshold = -1;
    int x = 0, y = 0;

    while (n--)
    {
        int a, b; cin >> a >> b;
        int inc = 0;
        if (!(x > b || y > a))
        {
            inc = min(a, b) - max({x, y, threshold}) + 1;
            threshold = min(a, b) + 1;
        }
        ans += inc;
        x = a;
        y = b;
    }

    cout << ans << "\n";

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}
