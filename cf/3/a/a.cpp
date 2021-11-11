#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    string from, to; cin >> from >> to;

    int dc = to[0] - from[0];
    int dr = to[1] - from[1];

    vector<string> moves;
    while (dc || dr) {
        string m = "";
        if (dc < 0) {
            m += 'L';
            dc++;
        } else if (dc > 0) {
            m += 'R';
            dc--;
        }

        if (dr < 0) {
            m += 'D';
            dr++;
        } else if (dr > 0) {
            m += 'U';
            dr--;
        }
        moves.push_back(m);
    }

    cout << moves.size() << "\n";
    for (string m : moves) cout << m << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

