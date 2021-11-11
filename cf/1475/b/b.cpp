#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    ll n; cin >> n;

    for (int a = 0; a * 2020 <= n; a++)
    {
        for (int b = 0; a * 2020 + b * 2021 <= n; b++)
        {
            if (a * 2020 + b * 2021 == n)
            {
                cout << "YES\n";
                return;
            }
        }
    }
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
