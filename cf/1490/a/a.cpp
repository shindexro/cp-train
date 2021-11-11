#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        int mx = max(arr[i], arr[i-1]);
        int mn = min(arr[i], arr[i-1]);
        while (mx > mn * 2)
        {
            mn *= 2;
            ans++;
        }
    }
    cout << ans << "\n";
        
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
