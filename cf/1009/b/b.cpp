#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    string s; cin >> s;
    int n = s.size();

    // 1s can be placed anywhere
    int idx = s.find_first_of('2');
    if (idx == -1)
        idx = n;
    string ans = "";
    for (int i = idx; i < n; i++)
    {
        if (s[i] != '1')
            ans += s[i];
    }
    int pre0 = count(s.begin(), s.begin() + idx, '0');
    int cnt1 = count(s.begin(), s.end(), '1');
    while (pre0--)
        cout << '0';
    while (cnt1--)
        cout << '1';    
    cout << ans << "\n";

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}
