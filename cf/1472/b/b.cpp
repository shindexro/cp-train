#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n; cin >> n;
    int ones = 0, twos = 0;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        if (a == 1)
            ones++;
        else
            twos++;
    }

    if (ones % 2 == 0 && (twos % 2 == 0 || ones >= 2))
        cout << "YES\n";
    else
        cout << "NO\n";

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
