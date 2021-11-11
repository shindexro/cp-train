#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    string s; cin >> s;

    int from = s.find_first_of('1');
    int to = s.find_last_of('1');

    if (from == -1) {
        cout << 0 << "\n";
        return;
    }
    cout << count(s.begin() + from, s.begin() + to, '0') << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}

