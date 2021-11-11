#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int lo = 1, hi = 1000;
    for (int i = 0; i < n; i++)
    {
        lo = max(lo, a[i]);
        hi = min(hi, b[i]);
    }
    cout << max(0, hi - lo + 1);
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

