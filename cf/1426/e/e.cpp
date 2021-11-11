#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    vector<int> a(3), b(3);
    for (int &x : a)
        cin >> x;
    for (int &x : b)
        cin >> x;

    int mn = -1, mx = -1;
    if (a[0] + a[1] <= b[0])
        mn = b[0] - a[0] - a[1];
    else if (a[0] < b[2])
        mn = max(0, a[1] - b[0] - b[1]);
    else if (a[0] > b[0] + b[2])
        mn = a[0] - b[0] - b[2];
    else
        mn = 0;

    mx = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);

    cout << mn << " " << mx << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}
