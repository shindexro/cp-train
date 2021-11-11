#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int k; cin >> k;

    int total = 100;
    int g = gcd(total, k);
    while (g != 1)
    {
        k /= g;
        total /= g;
        g = gcd(total, k);
    }
    cout << total << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
