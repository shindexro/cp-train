#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n, x; cin >> n >> x;
    vector<int> as(n), bs(n);
    for (int i = 0; i < n; i++) cin >> as[i];
    for (int i = 0; i < n; i++) cin >> bs[i];

    sort(as.begin(), as.end());
    sort(bs.rbegin(), bs.rend());
    for (int i = 0; i < n; i++)
    {
        if (as[i] + bs[i] > x)
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
