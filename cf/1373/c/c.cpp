#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    string s; cin >> s;
    int cnt = 0;
    ll res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '+')
            cnt++;
        else
            cnt--;

        if (cnt < 0)
        {
            cnt++;
            res += i + 1;
        }
    }
    res += s.size();
    cout << res << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
