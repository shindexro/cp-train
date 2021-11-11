#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n, m; cin >> n >> m;
    int negs = 0;
    int mn = INT_MAX;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int a; cin >> a;
            if (a < 0)
                negs++;
            
            a = abs(a);
            total += a;
            mn = min(mn, a);
        }
    }

    if (negs % 2 == 0)
    {
        cout << total << "\n";
    }
    else
    {
        cout << total - 2*mn << "\n";
    }

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
