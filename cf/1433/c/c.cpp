#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    bool allSame = true;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] != v[0])
        {
            allSame = false;
        }
        mx = max(mx, v[i]);
    }
    if (allSame)
    {
        cout << "-1\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (v[i] == mx)
        {
            if ((i > 0 && v[i-1] < mx) || (i < n-1 && v[i+1] < mx))
            {
                cout << i+1 << "\n";
                return;
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
