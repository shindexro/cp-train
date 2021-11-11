#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n, k1, k2; cin >> n >> k1 >> k2;
    int w, b; cin >> w >> b;

    int k = k1 + k2;
    if (w <= k/2 && b <= (2*n-k)/2)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}

