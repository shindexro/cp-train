#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    vector<int> v(n);
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        total += v[i];
    }

    int maxSeg = 0;
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur += v[i];
        cur = max(0, cur);
        maxSeg = max(maxSeg, cur);
    }

    int ans = -(total - maxSeg) + maxSeg;
    cout << ans << "\n";

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}
