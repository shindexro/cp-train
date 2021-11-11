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

    vector<int> dp(525, -1);
    for (int i = 0; i < n; i++) {
        for (int a = 0; a <= 520; a++) {
            if (dp[a] != -1 && v[i] > dp[a]
                && (dp[a ^ v[i]] == -1 || v[i] < dp[a ^ v[i]])) {
                dp[a ^ v[i]] = v[i];
            }
        }

        if (dp[v[i]] == -1 || v[i] < dp[v[i]]) {
            dp[v[i]] = v[i];
        }
    }

    dp[0] = 0;
    vector<int> ans;
    for (int a = 0; a <= 520; a++) {
        if (dp[a] != -1) {
            ans.push_back(a);
        }
    }

    cout << ans.size() << "\n";
    for (int a : ans) {
        cout << a << " ";
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
