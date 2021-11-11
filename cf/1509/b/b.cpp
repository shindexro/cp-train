#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    string s; cin >> s;

    int tcount = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'T') tcount++;
        else if (tcount > 0) tcount--;
        else {
            cout << "NO\n";
            return;
        }
    }
    if (tcount != n / 3) { cout << "NO\n"; return; }
    reverse(s.begin(), s.end());
    tcount = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'T') tcount++;
        else if (tcount > 0) tcount--;
        else {
            cout << "NO\n";
            return;
        }
    }

    if (tcount != n / 3) cout << "NO\n";
    else cout << "YES\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}

