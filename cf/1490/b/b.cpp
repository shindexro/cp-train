#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n; cin >> n;
    int c[3];
    c[0] = c[1] = c[2] = 0;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        c[a % 3]++;
    }

    int target = n / 3;
    int ans = 0;
    while (c[0] != target || c[1] != target || c[2] != target)
    {
        for (int i = 0; i < 3; i++)
        {
            if (c[i] > target)
            {
                c[(i+1) % 3] += c[i] - target;
                ans += c[i] - target;
                c[i] = target;
            }
        }
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
