#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int tc)
{
    int a, b;
    cin >> a >> b;
    int ans = 0;

    while (b == 1 || log(a) / log(b) > log(a) / log(b + 1) + 1) {
        b++;
        ans++;
    }

    while (a) {
        a /= b;
        ans++;
    }

    cout << ans << "\n";
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
