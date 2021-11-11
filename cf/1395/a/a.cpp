#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

bool ok(ll r, ll g, ll b, ll w)
{
    int odds = 0;
    if (r & 1)
        odds++;
    if (g & 1)
        odds++;
    if (b & 1)
        odds++;
    if (w & 1)
        odds++;

    return odds <= 1;
}

void solve(int tc)
{
    ll r, g, b, w;
    cin >> r >> g >> b >> w;

    if (ok(r, g, b, w) || (r && g && b && ok(r - 1, g - 1, b - 1, w + 3))) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve(t);
    }
}
