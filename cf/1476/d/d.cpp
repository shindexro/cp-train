#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n; cin >> n;
    string s; cin >> s;

    int preleft[n+1], preright[n+1];
    preleft[0] = preright[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i-1] == 'L')
        {
            preleft[i] = preright[i-1] + 1;
            preright[i] = 0;
        }
        else
        {
            preright[i] = preleft[i-1] + 1;
            preleft[i] = 0;
        }
    }

    int sufleft[n+1], sufright[n+1];
    sufleft[n] = sufright[n] = 0;
    for (int i = n-1; i >= 0; i--)
    {
        if (s[i] == 'L')
        {
            sufleft[i] = sufright[i+1] + 1;
            sufright[i] = 0;
        }
        else
        {
            sufright[i] = sufleft[i+1] + 1;
            sufleft[i] = 0;
        }
    }

    for (int i = 0; i <= n; i++)
    {
        cout << 1 + preleft[i] + sufright[i] << " ";
    }
    cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
