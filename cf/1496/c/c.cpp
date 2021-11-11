#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve(int tc)
{
    int n;
    cin >> n;
    vector<ll> xs, ys;
    for (int i = 0; i < 2 * n; i++) {
        ll x, y;
        cin >> x >> y;

        if (x < 0) {
            x = -x;
        }
        if (y < 0) {
            y = -y;
        }

        if (x) {
            xs.push_back(x);
        } else {
            ys.push_back(y);
        }
    }

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    long double ans = 0;
    for (int i = 0; i < n; i++) {
        ans += 1.0L * sqrt(xs[i] * xs[i] + ys[i] * ys[i]);
    }
    cout << fixed << setprecision(12) << ans << "\n";
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
