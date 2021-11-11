#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n; cin >> n;

    int side = sqrt(n/2);
    if (n % 2 == 1)
    {
        cout << "NO\n";
        return;
    }
    else if (side * side == n/2)
    {
        cout << "YES\n";
        return;
    }
    
    n /= 2;
    side = sqrt(n/2);
    if (n % 2 == 1)
    {
        cout << "NO\n";
        return;
    }
    else if (side * side == n/2)
    {
        cout << "YES\n";
        return;
    }
    else
    {
        cout << "NO\n";
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
