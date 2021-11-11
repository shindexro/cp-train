#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(string s)
{
    int l = 0, r = s.size() - 1;
    while (l < r)
    {
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

void solve(int _t)
{
    string s; cin >> s;

    if (!check("a" + s))
    {
        cout << "YES\n";
        cout << "a" + s << "\n";
    }
    else if (!check(s + "a"))
    {
        cout << "YES\n";
        cout << s + "a" << "\n";
    }
    else
    {
        cout << "NO\n";
    }


}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
