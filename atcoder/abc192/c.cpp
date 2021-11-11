#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int f(int n)
{
    string s = to_string(n);
    sort(s.begin(), s.end());
    int g2 = stoi(s);
    reverse(s.begin(), s.end());
    int g1 = stoi(s);
    return g1 - g2;
}

void solve(int _t)
{
    int n, k; cin >> n >> k;
    while (k--)
        n = f(n);
    cout << n;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

