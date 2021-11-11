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

int fac(int x)
{
    int y = 1;
    for (int i = 2; i <= x; i++)
        y = mul(y, i);
    return y;
}

int combin(int x, int y)
{
    return divide(fac(x), mul( fac(y), fac(x-y) ));
}



void solve(int _t)
{
    int n; cin >> n;
    int arr[2*n];
    for (int i = 0; i < 2*n; i++) cin >> arr[i];

    sort(arr, arr + 2*n);
    
    int ans = 0;
    int times = combin(2*n-1, n-1);
    for (int i = 0; i < n; i++)
    {
        int lo = arr[i], hi = arr[2*n-i-1];
        ans = sub(ans, mul(lo, times));
        ans = add(ans, mul(hi, times));
    }
    ans = mul(ans, 2);
    cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}
