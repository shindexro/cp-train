#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    string s; cin >> s;

    int zeros = count(s.begin(), s.end(), '0');
    if (zeros % 2 == 1 || s[0] == '0' || s[n-1] == '0')
    {
        cout << "NO\n";
        return;
    }

    string a1 = s;
    int ones = n - zeros;
    int cur = a1.find_first_of('1');
    for (int i = 0; i < ones/2; i++)
    {
        a1[cur] = '(';
        cur = a1.find_first_of('1', cur + 1);
    }
    replace(a1.begin(), a1.end(), '1', ')');

    for (int i = 0; i < n; i++)
    {
        if (a1[i] == '0')
        {
            if (zeros % 2 == 0)
                a1[i] = '(';
            else
                a1[i] = ')';
            zeros--;
        }
    }
    string a2 = a1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            a2[i] = (a2[i] == '(') ? ')' : '(';
    }
    
    cout << "YES\n";
    cout << a1 << "\n";
    cout << a2 << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}

