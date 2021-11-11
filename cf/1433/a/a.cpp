#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int x; cin >> x;
    int d = x % 10;
    int ans = (d-1) * 10;
    for (int i = 1; x > 0; i++)
    {
        x /= 10;
        ans += i;
    }
    cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
