#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    ll n, g, b; cin >> n >> g >> b;

    ll minG = (n + 1) / 2;
    ll p = minG / g;
    if (minG % g == 0) {
        cout << max(n, p * g + (p - 1) * b) << "\n";
    } else {
        cout << max(n, p * (g + b) + minG % g) << "\n";
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

