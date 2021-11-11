#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    string s; cin >> s;
    int ocnt = count(s.begin(), s.end(), 'o');
    int ans = 0;
    for (int i = 0; i < 10000; i++)
    {
        bool ok = true;
        unordered_set<int> seen;
        int cur = i;
        for (int j = 0; j < 4; j++)
        {
            int d = cur % 10;
            if (s[d] == 'x')
                ok = false;
            else if (s[d] == 'o')
                seen.insert(d);
            cur /= 10;
        }
        if (ok && seen.size() == ocnt)
            ans++;
    }
    cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

