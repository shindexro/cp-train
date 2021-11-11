#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const double PI = atan(1) * 4;

double dist(double x0, double y0, double x1, double y1)
{
    double dx = abs(x0-x1);
    double dy = abs(y0-y1);
    return sqrt(dx*dx + dy*dy);
}

void solve(int tc)
{
    int n; cin >> n;
    double x0, y0; cin >> x0 >> y0;
    double x2, y2; cin >> x2 >> y2;
    
    double xmid = (x0 + x2) / 2;
    double ymid = (y0 + y2) / 2;
    double r = dist(xmid, ymid, x0, y0);
    double theta = 2 * PI / n + atan2(y0 - ymid, x0 - xmid);

    cout << fixed << setprecision(9);
    cout << xmid + r * cos(theta) << " " << ymid + r * sin(theta) << "\n";

}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++)
        solve(t);
}

