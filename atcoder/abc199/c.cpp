#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    string s; cin >> s;
    int q; cin >> q;
    
    bool flipped = false;
    while (q--)
    {
        int t, a, b; cin >> t >> a >> b;
        a--;
        b--;
        if (t == 1)
        {
            if (flipped)
            {
                a = (a + n) % (2 * n);
                b = (b + n) % (2 * n);
            }
            swap(s[a], s[b]);
        }
        else
        {
            flipped = !flipped;
        }
    }
    string ans = "";
    if (flipped)
        ans += s.substr(n, n) + s.substr(0, n);
    else
        ans = s;
    cout << ans << "\n";

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

