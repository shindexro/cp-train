#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n, x; cin >> n >> x;
    vector<int> arr(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    vector<int> quot(arr);
    bool shutdown = false;
    while (!shutdown)
    {
        for (int i = 0; i < n; i++)
        {
            if (quot[i] % x == 0)
            {
                sum += arr[i];
                quot[i] /= x;
            }
            else
            {
                shutdown = true;
                break;
            }
        }
    }

    cout << sum << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
