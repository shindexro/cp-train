#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int a : arr)
    {
        int rt = sqrt(a);
        if (rt * rt != a)
        {
            cout << "YES\n";
            return;
        }
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
