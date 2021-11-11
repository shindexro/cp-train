#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    int n,m; cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    unordered_set<int> seen;
    for (int i = 0; i < n; i++) {
        arr[i] %= m;
        if (seen.find(arr[i]) != seen.end()) {
            cout << 0;
            return;
        }
        seen.insert(arr[i]);
    }

    int ans = 1;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            ans = (ans * (m + arr[j] - arr[i])) % m;

    cout << ans;

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

