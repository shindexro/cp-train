#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    int xmin = -1e5, xmax = 1e5;
    int ymin = -1e5, ymax = 1e5;

    while (n--)
    {
        int x, y, f1, f2, f3, f4;
        cin >> x >> y >> f1 >> f2 >> f3 >> f4;
        
        if (!f1)
            xmin = max(xmin, x);
        if (!f2)
            ymax = min(ymax, y);
        if (!f3)
            xmax = min(xmax, x);
        if (!f4)
            ymin = max(ymin, y);
    }

    if (xmin <= xmax && ymin <= ymax)
        cout << 1 << " " << xmin << " " << ymin << "\n";
    else
        cout << 0 << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
