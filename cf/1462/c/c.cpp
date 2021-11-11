#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int x; cin >> x;
    if (x > 45)
    {
        cout << "-1\n";
        return;
    }

    int ans = 0;
    int d = 9, b = 1;
    while (x > 0)
    {
        int digit = min(x, d);
        ans += digit * b;
        b *= 10;
        x -= digit;
        d--;
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
