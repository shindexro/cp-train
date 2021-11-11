#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))

int mask(int a)
{
    if (a == 0)
        return 0;
    int m = 1, q = 0;
    while (a % 2 == 0)
    {
        a /= 2;
        q++;
    }
    m *= (q % 2 == 0) ? 1 : 2;

    for (int i = 3; i*i <= a; i += 2)
    {
        q = 0;
        while (a % i == 0)
        {
            a /= i;
            q++;
        }
        m *= (q % 2 == 0) ? 1 : i;
    }
    m *= a;
    return m;
}

void solve(int _t)
{
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        v[i] = mask(a);
    }

    int ans = 1;
    unordered_set<int> seen;
    for (int a : v)
    {
        // cout << a << " ";
        if (seen.find(a) != seen.end())
        {
            seen.clear();
            ans++;
        }
        seen.insert(a);
    }
    cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
