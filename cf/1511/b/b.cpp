#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int a, b, c; cin >> a >> b >> c;
    int x = 1, y = 1;

    while (x < pow(10, a-1)) x *= 2;
    while (y < pow(10, c-1)) y *= 2;
    while (y < pow(10, b-1)) y *= 3;

    cout << x << " " << y << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}

