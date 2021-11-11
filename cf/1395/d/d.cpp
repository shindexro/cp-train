#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve(int tc)
{
    ll n, d, m;
    cin >> n >> d >> m;
    vector<ll> safe, dang;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a > m) {
            dang.push_back(a);
        } else {
            safe.push_back(a);
        }
    }
    sort(safe.rbegin(), safe.rend());
    sort(dang.rbegin(), dang.rend());

    vector<ll> pre_safe, pre_dang;
    pre_safe.push_back(0);
    pre_dang.push_back(0);
    for (int i = 0; i < safe.size(); i++) {
        pre_safe.push_back(pre_safe[i] + safe[i]);
    }
    for (int i = 0; i < dang.size(); i++) {
        pre_dang.push_back(pre_dang[i] + dang[i]);
    }

    ll ans = 0;
    for (int i = 0; i <= safe.size(); i++) {
        int dang_days = (n - i - 1) / (d + 1) + 1;
        ans = max(ans, pre_safe[i] + pre_dang[min(dang_days, (int)dang.size())]);
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve(t);
    }
}
