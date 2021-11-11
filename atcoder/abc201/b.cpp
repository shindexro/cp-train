#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    map<int,string> m;
    for (int i = 0; i < n; i++)
    {
        string s; int t; cin >> s >> t;
        m[t] = s;
    }
    auto it = m.rbegin();
    it++;
    cout << (*it).second << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

