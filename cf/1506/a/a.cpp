#include <bits/stdc++.h>
using namespace std;
#define umap unordered_map
typedef long long ll;

void solve(int t)
{
    ll n, m, x;
	cin >> n >> m >> x;

	ll col = (x - 1) / n;
	ll row = (x - 1) % n;
	ll ans = row * m + col + 1;

    cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("1506A_case.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}