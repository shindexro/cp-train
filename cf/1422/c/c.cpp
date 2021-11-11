#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))
#define N ((int)(2e5 + 7))

ll inv[N], fact[N], fact_inv[N];

void modPrep()
{
    inv[0] = 0;
    inv[1] = 1;
    for (int i = 2; i < N; i++)
    {
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    }
    fact[0] = fact_inv[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = fact[i-1] * i % MOD;
        fact_inv[i] = fact_inv[i-1] * inv[i] % MOD;
    }
}

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

int divide(int x, int y)
{
    return mul(x, inv[y]);
}

int combin(int n, int k)
{
    if (n < k)
        return 0;
    return mul(mul(fact[n], fact_inv[n-k]), fact_inv[k]);
}

void solve(int _t)
{
    string s; cin >> s;
    int n = s.size();

    int ans = 0;
    int rfactor = 0, rbase = 1;
    for (int i = n-1; i >= 0; i--)
    {
        int d = s[i] - '0';
        int c = mul(mul(i+1, i), 500000004);
        int factor = add(rfactor, mul(c, rbase));
        ans = add(ans, mul(d, factor));
        
        rfactor = add(rfactor, mul(rbase, n-i));
        rbase = mul(rbase, 10);
    }
    cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	modPrep();
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}


