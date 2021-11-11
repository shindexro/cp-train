#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int max_median(vector<int>& v, int n, int k)
{
    int ans = 0;
    multiset<int> left, right;
    for (int i = 0; i < n; i++) {
        right.insert(v[i]);
        if (left.size() + right.size() < k) {
            continue;
        }

        while (right.size() > k - (k + 1) / 2) {
            int a = *right.begin();
            right.erase(right.begin());
            left.insert(a);
        }
        while (right.size() && *(--left.end()) > *right.begin()) {
            int a = *(--left.end()), b = *right.begin();
            left.erase(--left.end());
            right.erase(right.begin());
            left.insert(b);
            right.insert(a);
        }

        ans = max(ans, *(--left.end()));
        int rem = v[i - k + 1];
        if (right.size() == 0 || rem < *right.begin()) {
            left.erase(left.lower_bound(rem));
        } else {
            right.erase(right.lower_bound(rem));
        }
    }
    return ans;
}

void solve(int tc)
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int& i : v)
        cin >> i;

    cout << max(max_median(v, n, k), max_median(v, n, k + 1)) << "\n";
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
