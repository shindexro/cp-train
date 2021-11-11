#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int lo = INT_MAX, hi = INT_MIN;
    for (int i = 0; i < n; i++)
        if (arr[i] != -1) {
            if ((i > 0 && arr[i - 1] == -1) || (i + 1 < n && arr[i + 1] == -1)) {
                lo = min(lo, arr[i]);
                hi = max(hi, arr[i]);
            }
        }
    int k = (lo + hi) / 2;
    int diff = INT_MIN;

    replace(arr.begin(), arr.end(), -1, k);

    for (int i = 1; i < n; i++) {
        diff = max(diff, abs(arr[i] - arr[i - 1]));
    }
    cout << diff << " " << k << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
        solve(t);
}
