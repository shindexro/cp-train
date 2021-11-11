#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    ll a, b; cin >> a >> b;
    if (b == 1)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    ll z = 2 * a * b;
    cout << a << " " << z-a << " " << z << "\n";

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
