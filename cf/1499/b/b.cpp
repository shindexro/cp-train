#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    string s; cin >> s;

    int idx = s.find("11");

    if (idx == -1 || s.find("00", idx) == -1)
        cout << "YES\n";
    else
        cout << "NO\n";

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}

