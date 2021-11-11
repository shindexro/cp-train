#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve(int tc)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    ll ans = 0;
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] < 0) {
            if (-v[i] > cnt) {
                ans += -v[i] - cnt;
                cnt = 0;
            } else {
                cnt += v[i];
            }
        } else {
            cnt += v[i];
        }
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
