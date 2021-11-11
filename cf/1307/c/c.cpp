#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    string s; cin >> s;
    unordered_map<char, ll> cfreq;
    unordered_map<string, ll> pfreq;
    
    for (char c : s) {
        for (auto cf : cfreq) {
            pfreq[string()+cf.first+c] += cf.second;
        }
        cfreq[c]++;
    }

    ll ans = 0;
    for (auto p : cfreq) ans = max(ans, p.second);
    for (auto p : pfreq) ans = max(ans, p.second);
    
    cout << ans << "\n";

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

