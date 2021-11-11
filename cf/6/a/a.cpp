#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    vector<int> s(4);
    for (int i = 0; i < 4; i++) cin >> s[i];
    sort(s.begin(), s.end());

    if (s[0] + s[1] > s[2] || s[1] + s[2] > s[3])
        cout << "TRIANGLE";
    else if (s[0] + s[1] == s[2] || s[1] + s[2] == s[3])
        cout << "SEGMENT";
    else
        cout << "IMPOSSIBLE";
    
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

