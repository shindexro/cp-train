#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    string s; cin >> s;

    set<char> seen;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && s[i-1] != s[i] && seen.find(s[i]) != seen.end())
        {
            cout << "NO\n";
            return;
        }
        seen.insert(s[i]);
    }
    cout << "YES\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
