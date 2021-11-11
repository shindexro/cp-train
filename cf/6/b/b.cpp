#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    int n, m;
    char c;
    cin >> n >> m >> c;

    vector<string> room(n);
    for (int i = 0; i < n; i++) cin >> room[i];

    unordered_set<char> deputies;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (room[i][j] == c) {
                if (i > 0) deputies.insert(room[i-1][j]);
                if (i + 1 < n) deputies.insert(room[i+1][j]);
                if (j > 0) deputies.insert(room[i][j-1]);
                if (j + 1 < m) deputies.insert(room[i][j+1]);
            }
    deputies.erase('.');
    deputies.erase(c);
    cout << deputies.size();

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

