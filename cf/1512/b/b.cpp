#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n; cin >> n;
    vector<string> rs(n);
    int r0, c0, r1, c1;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        rs[i] = s;
    }
    bool firstFound = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (rs[i][j] == '*') {
                if (!firstFound) { r0 = i; c0 = j; firstFound = true; }
                else { r1 = i; c1 = j; }
            }
        }
    }

    if (r0 != r1 && c0 != c1) {
        rs[r0][c1] = rs[r1][c0] = '*';
    } else if (r0 == r1) {
        if (r0 > 0) rs[r0-1][c0] = rs[r0-1][c1] = '*';
        else rs[r0+1][c0] = rs[r0+1][c1] = '*';
    } else {
        if (c0 > 0) rs[r0][c0-1] = rs[r1][c0-1] = '*';
        else rs[r0][c0+1] = rs[r1][c0+1] = '*';
    }
    for (string r : rs) cout << r << "\n";

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}

