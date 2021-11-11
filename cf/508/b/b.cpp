#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    string s; cin >> s;
    int n = s.size();
    int lst = s[n-1] - '0';

    for (int i = 0; i < n; i++)
    {
        int d = s[i] - '0';
        if (d % 2 == 0 && d < lst)
        {
            swap(s[i], s[n-1]);
            cout << s;
            return;
        }
    }

    for (int i = n-1; i >= 0; i--)
    {
        if ((s[i] - '0') % 2 == 0)
        {
            swap(s[i], s[n-1]);
            cout << s;
            return;
        }
    }

    cout << -1;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}
