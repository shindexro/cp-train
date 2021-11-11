#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n; cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    ll sum = 0;
    for (int i = 0; i < n; i++) sum ^= arr[i];

    if (sum == 0)
    {
        cout << "YES\n";
        return;
    }
    // cout << "sum: " << sum << "\n";

    int start = 0;
    int idx = 0;
    ll cursum = 0;
    while (idx < n)
    {
        if (cursum == sum)
        {
            start = idx;
            cursum = 0;
        }
        cursum ^= arr[idx++];
    }
    if (cursum == sum && start != 0)
    {
        cout << "YES\n";
        return;
    }
    
    cout << "NO\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
