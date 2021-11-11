#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve(int tc)
{
    int n, q, k;
    cin >> n >> q >> k;
    vector<ll> v(n);
    for (ll& i : v)
        cin >> i;

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << (v[r] - v[l] - 1) * 2 - (r - l - 1) * 2 + (v[l] - 1) + (k - v[r]) << "\n";
    }
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
