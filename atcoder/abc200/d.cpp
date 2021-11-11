#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    vector<int> a(n), b, c;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        a[i] = x % 200;
    }

    vector<int> seen(200);
    for (int i = 1; i <= 201; i++)
    {
        int mask = i;
        int cur = 0;
        for (int j = 0; j < n && mask; j++, mask >>= 1)
            if (mask & 1)
                cur = (cur + a[j]) % 200;

        if (seen[cur])
        {
            mask = i;
            for (int j = 0; mask; j++, mask >>= 1)
                if (mask & 1)
                    b.push_back(j);
            mask = seen[cur];
            for (int j = 0; mask; j++, mask >>= 1)
                if (mask & 1)
                    c.push_back(j);
            break;
        }
        else
            seen[cur] = i;

        if (__builtin_popcount(i) == n)
            break;
    }

    if (b.size() == 0)
    {
        cout << "NO";
        return;
    }

    cout << "YES\n";
    cout << b.size() << " ";
    for (int x : b)
        cout << x + 1 << " ";
    cout << "\n";

    cout << c.size() << " ";
    for (int x : c)
        cout << x + 1 << " ";
    cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

