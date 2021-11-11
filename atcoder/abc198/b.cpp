#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    while (n && n % 10 == 0)
        n /= 10;
    string s = to_string(n);
    if (equal(s.begin(), s.end(), s.rbegin()))
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

