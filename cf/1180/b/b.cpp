#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    vector<int> v(n);
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        if (a >= 0)
            a = -a - 1;
        v[i] = a;

        if (v[i] < v[idx])
            idx = i;
    }

    if (n % 2 == 1)
        v[idx] = -v[idx] - 1;

    for (int a : v)
        cout << a << " ";
    cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}
