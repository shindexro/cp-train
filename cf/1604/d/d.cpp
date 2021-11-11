#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve(int tc)
{
    ll x, y;
    cin >> x >> y;
    if (y < x) {
        cout << x * x + y << "\n";
    } else if (y == x) {
        cout << x << "\n";
    } else {
        int r = ((x + y) / 2) % x;
        cout << y - r << "\n";
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
