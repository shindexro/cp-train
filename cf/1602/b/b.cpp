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

    vector<vector<int>> ans(n + 2, vector<int>(n));
    map<int, int> freq;
    for (int i = 0; i <= n; i++) {
        map<int, int> new_freq;
        for (int j = 0; j < n; j++) {
            if (i == 0) {
                ans[i][j] = v[j];
            } else {
                ans[i][j] = freq[ans[i - 1][j]];
            }
            new_freq[ans[i][j]]++;
        }
        freq.swap(new_freq);
    }

    int q;
    cin >> q;
    while (q--) {
        int x, k;
        cin >> x >> k;

        cout << ans[min(n, k)][x - 1] << "\n";
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
