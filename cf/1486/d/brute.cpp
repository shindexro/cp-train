#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve(int tc)
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int& i : v)
        cin >> i;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + k - 1; j < n; j++) {
            vector<int> w(v.begin() + i, v.begin() + j + 1);
            sort(w.begin(), w.end());
            ans = max(ans, w[(w.size() + 1) / 2 - 1]);
        }
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
