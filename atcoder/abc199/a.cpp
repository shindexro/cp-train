#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int a, b, c; cin >> a >> b >> c;
    if (a * a + b * b < c * c)
        cout << "Yes";
    else
        cout << "No";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

