#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve(int tc)
{
    ll p, a, b, c;
    cin >> p >> a >> b >> c;

    if (p % a == 0 || p % b == 0 || p % c == 0) {
        cout << "0\n";
        return;
    }

    cout << min({ a - p % a, b - p % b, c - p % c }) << "\n";
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
