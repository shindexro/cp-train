#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int a, b; cin >> a >> b;
    string s; cin >> s;

    int ans = 0;
    int prevMine = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            if (prevMine == -1)
                ans += a;
            else
                ans += min(a, b * (i-prevMine-1));
            prevMine = i;
        }
    }
    cout << ans << "\n";

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
