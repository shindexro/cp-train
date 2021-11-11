#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    int x, y, a, b;
    cin >> x >> y >> a >> b;

    int d = y - x;
    if (d % (a + b) == 0) {
        cout << d / (a + b) << "\n";
    } else {
        cout << -1 << "\n";
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

