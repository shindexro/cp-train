#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string reverseStr(string s)
{
    string r(s);
    reverse(r.begin(), r.end());
    return r;
}

void solve(int t)
{
    int n, m; cin >> n >> m;
    set<string> ss;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        ss.insert(s);
    }

    string ans = "";
    string center = "";
    while (ss.size()) {
        string s = *ss.begin();
        string r = reverseStr(s);
        if (!s.compare(r)) {
            center = s;
        } else if (ss.find(r) != ss.end()) {
            ans += s;
            ss.erase(r);
        }
        ss.erase(s);
    }

    cout << ans.size() * 2 + center.size() << "\n";
    cout << ans << center;
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";


}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

