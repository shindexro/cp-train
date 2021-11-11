#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    string s; cin >> s;
    ll m; cin >> m;

    if (s.size() == 1 && stoi(s) <= m)
    {
        cout << 1;
        return;
    }
    if (s.size() == 2)
    {
        ll d1 = s[0] - '0';
        ll d2 = s[1] - '0';
        ll base = (m - d2) / d1;
        cout << base - max(d1, d2);
        return;
    }
    if (s.size() == 3)
    {
        ll d1 = s[0] - '0';
        ll d2 = s[1] - '0';
        ll d3 = s[2] - '0';
        ll disc = d2 * d2 - 4 * d1 * (d3 - m);
        ll base = (-d2 + sqrt(disc)) / 2 / d1;
        cout << base - max({d1, d2, d3});
        return;
    }

    ll d = *max_element(s.begin(), s.end()) - '0';
    ll base = d;
    ll cur = 0;
    while (cur <= m)
    {
        base++;
        cur = 0;
        ll dbase = 1;
        bool ok = true;
        for (int i = 0; i < s.size(); i++)
        {
            if (cur > m || dbase > m)
            {
                ok = false;
                break;
            }
            cur += (s[s.size()-i-1] - '0') * dbase;
            dbase *= base;
        }
        if (!ok)
            break;
        cerr << cur << "\n";
    }

    cout << base - d - 1;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

