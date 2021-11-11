#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

bool is_subset_sum(vector<int>& v, int n, int sum)
{
    bool subset[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        subset[i][0] = true;

    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < v[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= v[i - 1])
                subset[i][j] = subset[i - 1][j]
                    || subset[i - 1][j - v[i - 1]];
        }
    }
    return subset[n][sum];
}

void solve(int tc)
{
    int n;
    cin >> n;
    vector<int> v(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> v[i];
    }

    vector<int> frag;
    int last = 2 * n;
    while (last != 0) {
        int idx = max_element(v.begin(), v.begin() + last) - v.begin();
        frag.push_back(last - idx);
        last = idx;
    }

    sort(frag.rbegin(), frag.rend());

    if (is_subset_sum(frag, frag.size(), n)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
