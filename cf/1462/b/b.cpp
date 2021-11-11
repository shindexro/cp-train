#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    string s; cin >> s;

    if (s.size() < 4)
    {
        cout << "NO\n";
        return;
    }

    int i = 0, j = 0;
    string t = "2020";
    while (s[i] == t[j])
    {
        i++;
        j++;
    }

    for (int k = n-(4-j); k < n; k++)
    {
        if (s[k] != t[j])
        {
            cout << "NO\n";
            return;
        }
        j++;
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
