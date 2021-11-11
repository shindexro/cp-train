#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve(int tc)
{
    int a, b, c, m;
    cin >> a >> b >> c >> m;

    int mn = max({ a - b - c - 1, b - a - c - 1, c - a - b - 1, 0 });
    int mx = a + b + c - 3;

    if (mn <= m && m <= mx)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
        solve(t);
}
