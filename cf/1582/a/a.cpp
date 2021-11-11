#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve(int tc)
{
    ll a, b, c;
    cin >> a >> b >> c;

    ll sum = a + 2 * b + 3 * c;
    if (sum & 1) {
        cout << "1\n";
    } else {
        cout << "0\n";
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
