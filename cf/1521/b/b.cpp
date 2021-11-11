#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int nextOdd(int a)
{
    a++;
    while (a % 2 == 0)
        a++;
    return a;
}

void solve(int _t)
{
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int mnIdx = 0;
    for (int i = 0; i < n; i++)
        if (a[i] < a[mnIdx])
            mnIdx = i;

    int cur = nextOdd(a[mnIdx]);
    int op = (mnIdx == 0) ? n-1 : n;
    cout << op << "\n";
    if (mnIdx != 0)
        cout << 1 << " " << mnIdx+1 << " " << a[mnIdx] << " " << cur << "\n";
    for (int i = 2; i <= n; i++)
    {
        cout << 1 << " " << i << " " << a[mnIdx] << " " << cur << "\n";
        cur += 2;
    }
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
