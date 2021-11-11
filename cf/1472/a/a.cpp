#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int w, h, n; cin >> w >> h >> n;

    int wparts = 1, hparts = 1;
    while (w % 2 == 0)
    {
        wparts <<= 1;
        w >>= 1;
    }
    while (h % 2 == 0)
    {
        hparts <<= 1;
        h >>= 1;
    }
    int parts = wparts * hparts;
    if (parts >= n)
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
