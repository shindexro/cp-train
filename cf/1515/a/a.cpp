#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n, x; cin >> n >> x;
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    if (sum == x)
    {
        cout << "NO\n";
        return;
    }

    int cur = 0;
    for (int i = 0; i < n-1; i++)
    {
        cur += v[i];
        if (cur == x)
        {
            swap(v[i], v[i+1]);
            break;
        }
    }
    cout << "YES\n";
    for (int a : v)
        cout << a << " ";
    cout << "\n";


}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
