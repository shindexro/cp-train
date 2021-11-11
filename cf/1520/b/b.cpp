#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    string s = to_string(n);
    int len = s.size();
    int ans = (len - 1) * 9;
    
    int base = 1;
    for (int i = 0; i < len-1; i++)
    {
        base = base * 10 + 1;
    }
    int cur = base;
    while (cur <= n)
    {
        ans++;
        cur += base;
    }
    cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
