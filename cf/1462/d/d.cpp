#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    vector<int> v(n);
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        total += v[i];
    }

    for (int k = n; k >= 1; k--)
    {
        if (total % k != 0)
            continue;

        int target = total / k;
        int cur = 0;
        bool ok = true;
        for (int i = 0; i < n; i++)
        {
            cur += v[i];
            if (cur > target)
            {
                ok = false;
                break;
            }
            else if (cur == target)
            {
                cur = 0;
            }
        }
        if (ok)
        {
            cout << n - k << "\n";
            return;
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
