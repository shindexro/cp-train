#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve(int tc)
{
    int n, k;
    cin >> n >> k;
    set<int> nums;
    int mx = 0, mex = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        nums.insert(a);
        mx = max(mx, a);
    }

    while (nums.find(mex) != nums.end()) {
        mex++;
    }

    int ans;
    if (mex > mx) {
        ans = n + k;
    } else if (k && nums.find((mx + mex + 1) / 2) == nums.end()) {
        ans = n + 1;
    } else {
        ans = n;
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
