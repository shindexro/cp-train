#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n, l; cin >> n >> l;
    vector<double> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());
    double ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans = max(ans, (arr[i] - arr[i-1]) / 2.0);
    }
    ans = max(ans, arr[0]);
    ans = max(ans, l - arr.back());
    cout << setprecision(15);
    cout << ans << "\n";    
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}
