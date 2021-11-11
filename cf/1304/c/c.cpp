#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> cs(n);
    for (int i = 0; i < n; i++) {
        int t, l, h; cin >> t >> l >> h;
        cs[i] = {t, l, h};
    }

    int elapsed = 0;
    int lo = m;
    int hi = m;
    for (auto c : cs) {
        int t, l, h; tie(t, l, h) = c;
        int tdiff = t - elapsed;
        lo -= tdiff;
        hi += tdiff;

        if (!(hi < l || lo > h)) {
            lo = max(lo, l);
            hi = min(hi, h);
        } else {
            cout << "NO\n";
            return;
        }
        elapsed = t;
    }
    cout << "YES\n";

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}

