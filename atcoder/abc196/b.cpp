#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    string x; cin >> x;
    int dot = x.find('.');

    if (dot == -1)
        cout << x;
    else
        cout << x.substr(0, dot);
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

