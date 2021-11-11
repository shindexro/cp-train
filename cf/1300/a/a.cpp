#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    int n; cin >> n;
    int zeros = 0;
    int sum = 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        zeros += arr[i] == 0;
        sum += arr[i];
    }

    int ans = zeros;
    sum += zeros;

    if (sum == 0) ans++;
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

