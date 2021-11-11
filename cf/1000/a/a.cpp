#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    int n; cin >> n;
    unordered_map<string, int> freq;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        freq[s]++;
    }

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        freq[s]--;
    }

    int ans = 0;
    for (auto x : freq) {
        if (x.second > 0) ans += x.second;
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

