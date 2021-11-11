#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    int n, m; cin >> n >> m;
    vector<int> freq(m);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        freq[a % m]++;
    }

    int ans = 0;
    if (freq[0]) ans++;
    for (int i = 1; i <= m/2; i++) {
        if (!freq[i] || !freq[m - i]) {
            ans += freq[i] + freq[m - i];
        } else if (freq[i] == freq[m - i]) {
            ans++;
        } else {
            ans += abs(freq[i] - freq[m - i]);
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

