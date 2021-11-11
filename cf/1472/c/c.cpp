#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> score(n);
    int ans = 0;
    for (int i = n-1; i >= 0; i--)
    {
        if (i + arr[i] >= n)
            score[i] = arr[i];
        else
            score[i] = arr[i] + score[i + arr[i]];
        ans = max(ans, score[i]);
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
