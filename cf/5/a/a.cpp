#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    unordered_set<string> online;
    ll ans = 0;

    string line;
    while (getline(cin, line)) {
        if (line[0] == '+') {
            online.insert(line.substr(1));
        } else if (line[0] == '-') {
            online.erase(line.substr(1));
        } else {
            int idx = line.find(":");
            ans += (line.size() - idx - 1) * online.size();
        }
    }

    cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

