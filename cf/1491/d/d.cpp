#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int q; cin >> q;
    vector<pair<int,int>> v(q);
    for (int i = 0; i < q; i++)
    {
        int a, b; cin >> a >> b;
        v[i] = {a, b};
    }

    for (auto [a,b] : v)
    {
        bool ans = true;
        if (a > b)
            ans = false;
        else
        {
            int a1 = 0, b1 = 0;
            for (int i = 0; i < 31; i++)
            {
                if (a & 1) a1++;
                if (b & 1) b1++;
                if (b1 > a1)
                {
                    ans = false;
                    break;
                }
                a >>= 1;
                b >>= 1;
            }
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}
