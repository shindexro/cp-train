#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n; cin >> n;
    vector<ll> arr(n+2);
    for (int i = 0; i < n+2; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());
    ll sum = 0;
    for (ll a : arr) sum += a;

    ll val = sum - arr[n+1] * 2;
    auto it = lower_bound(arr.begin(), arr.end() - 1, val);
    int idx = it - arr.begin();
    if (idx < n+1 && *it == val) {
        for (int i = 0; i < n+1; i++)
            if (i != idx)
                cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    // last elem is corrupted, or -1
    if (sum - arr[n+1] - arr[n] == arr[n]) {
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << "\n";
    } else {
        cout << "-1\n";
    }
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}

