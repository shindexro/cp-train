#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))

int match(string a, string b, int i, int j)
{
    int len = 0;
    while (i < a.size() && j < b.size() && a[i] == b[j])
    {
        i++;
        j++;
        len++;
    }
    return len;
}


void solve(int _t)
{
    string a, b; cin >> a >> b;

    int mx = 0;
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < b.size(); j++)
        {
            mx = max(mx, match(a, b, i, j));
        }
    }
    cout << a.size() + b.size() - 2 * mx << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
