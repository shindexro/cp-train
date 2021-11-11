#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int add(int x, int y)
{
    // assume x and y in range [0, MOD] and MOD <= INT_MAX / 2
    x += y;
    while (x >= MOD) x -= MOD;
    while (x < 0) x += MOD;
    return x;
}

int sub(int x, int y)
{
    return add(x, MOD - y);
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int binpow(int x, int y)
{
    int z = 1;
    while (y > 0)
    {
        if (y % 2 == 1)
            z = mul(z, x);
        x = mul(x, x);
        y /= 2;
    }
    return z;
}

int inv(int x)
{
    return binpow(x, MOD - 2);
}

int divide(int x, int y)
{
    return mul(x, inv(y));
}

void solve(int _t)
{
    int n, m; cin >> n >> m;
    int w = 0;
    string b[n];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        w = add(w, count(b[i].begin(), b[i].end(), 'o'));
    }

    vector<vector<int>> dph(n, vector<int>(m));
    vector<vector<int>> dpv(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j+1<m && b[i][j]=='o' && b[i][j+1]=='o') {
                if (j-1>=0) {
                    dph[i][j] = sub(binpow(2, w-2), divide(dph[i][j-1], 2));
                } else {
                    dph[i][j] = binpow(2, w-2);
                }
            }
            if (i+1<n && b[i][j]=='o' && b[i+1][j]=='o') {
                if (i-1>=0) {
                    dpv[i][j] = sub(binpow(2, w-2), divide(dpv[i-1][j], 2));
                } else {
                    dpv[i][j] = binpow(2, w-2);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans = add(add(ans, dph[i][j]), dpv[i][j]);
    cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

