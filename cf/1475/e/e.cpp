#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))

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
    int p = 1;
    while (x) p = mul(p, x--);
    return p;
}

int combin(int x, int y)
{
    int d = mul(fac(y), fac(sub(x, y)));
    return divide(fac(x), d);
}


void solve(int _t)
{
    int n, k; cin >> n >> k;
    vector<int> blog(n);
    for (int i = 0; i < n; i++)
    {
        cin >> blog[i];
    }
    sort(blog.rbegin(), blog.rend());

    int pool = count(blog.begin(), blog.end(), blog[k-1]);
    int select = 0;
    while (k-select-1 >= 0 && blog[k-select-1] == blog[k-1])
        select++;
    cout << combin(pool, select) << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
