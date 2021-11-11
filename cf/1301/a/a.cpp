#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    string a, b, c; cin >> a >> b >> c;

    for (int i = 0; i < a.size(); i++) {
        if (c[i] == a[i] || c[i] == b[i]) continue;
        else {
            cout << "NO\n";
            return;
        }
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

