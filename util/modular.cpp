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

int C(int n, int r)
{
    if (n < r)
        return 0;
    return mul(mul(fact[n], fact_inv[n-r]), fact_inv[r]);
}
