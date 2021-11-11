#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n,m,a,b; cin >> n >> m >> a >> b;

    int special = n / m;
    int remain = n % m;
    int ans = a * n;
    ans = min(ans, special * b + remain * a);
    ans = min(ans, (special+1) * b);
    cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}
