#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    string s; cin >> s;

    int l = s.find_first_of('*');
    int r = s.find_last_of('*');

    ll ans = 0;
    int sheep = count(s.begin(), s.end(), '*');
    int lsheep = 0;
    for (int i = l; i <= r; i++)
    {
        if (s[i] == '.')
        {
            ans += min(lsheep, sheep - lsheep);
        }
        else
        {
            lsheep++;
        }
    }
    cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
