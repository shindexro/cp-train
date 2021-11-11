#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    int n; cin >> n;
    vector<int> arr(2*n);
    for (int i = 0; i < 2*n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    cout << arr[n] - arr[n-1] << "\n";

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}

