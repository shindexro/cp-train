#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve(int tc)
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> cand;
    int rem = n - (m - 1);
    for (int i = 0; i + rem <= n; i++) {
        cand.push_back(max(v[i], v[i + rem - 1]));
    }

    k = min(m - 1, k);
    int ans = 0;
    for (int i = 0; i <= k; i++) {
        int alt = *min_element(cand.begin() + i, cand.begin() + i + cand.size() - k);
        ans = max(ans, alt);
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
