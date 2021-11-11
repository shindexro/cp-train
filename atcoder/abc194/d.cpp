#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    int remain = n-1;
    double ans = 0;
    while (remain)
    {
        ans += 1.0 * n / remain;
        remain--;
    }
    cout << fixed << setprecision(9);
    cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

