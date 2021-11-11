#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int MOD = 1e9+7;

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

struct node
{
    node *prev;
    int val;
    node(int _v, node *_p) : val(_v), prev(_p) {};
};

void solve(int _t)
{
    int n; cin >> n;
    MOD = n;
    unordered_set<int> coprime(n);
    for (int i = 1; i < n; i++)
        coprime.insert(i);

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            for (int j = i; j < n; j += i)
            {
                coprime.erase(j);
            }
        }
    }

    int prod = 1;
    for (int a : coprime)
    {
        prod = mul(prod, a);
    }


    if (prod != 1)
        coprime.erase(prod);

    vector<int> ans(coprime.begin(), coprime.end());
    sort(ans.begin(), ans.end()); 
    cout << ans.size() << "\n";
    for (int a : ans)
        cout << a << " ";
    cout << "\n";
    
    
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}
