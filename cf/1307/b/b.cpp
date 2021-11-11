#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    int n, x; cin >> n >> x;
    int mx = 0;
    bool match = false;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        mx = max(mx, a);
        if (a == x) match = true;
    }
    if (match) {
        cout  << 1 << "\n";
    } else if (x % mx == 0) {
        cout << x / mx << "\n";
    } else {
        cout << max(1, x / mx) + 1 << "\n";
    }

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}

