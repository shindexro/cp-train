#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    if (b * d * f > a * c * e ||
            (a == 0 && b > 0 && d > 0) ||
            (c == 0 && d > 0))
        cout << "Ron\n";
    else
        cout << "Hermione\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}
