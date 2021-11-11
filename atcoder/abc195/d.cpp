#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n, m, q; cin >> n >> m >> q;
    vector<pair<int,int>> a(n);
    for (auto &p : a)
    {
        int w, v; cin >> w >> v;
        p = {w, v};
    }
    vector<int> b(m);
    for (auto &x : b)
        cin >> x;

    sort(a.begin(), a.end(), [&](auto x, auto y)
            {
                if (x.second != y.second) return x.second > y.second;
                else return x.first < y.first;    
            });

    while (q--)
    {
        int l, r; cin >> l >> r;
        l--;
        r--;
        vector<int> c;
        for (int i = 0; i < m; i++)
            if (!(l <= i && i <= r))
                c.push_back(b[i]);
        sort(c.begin(), c.end());

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < c.size(); j++)
            {
                if (a[i].first <= c[j])
                {
                    ans += a[i].second;
                    c[j] = 0;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }


}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

