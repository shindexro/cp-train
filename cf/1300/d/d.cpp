#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll dist(pii a, pii b)
{
    return (a.first - b.first) * (a.first - b.first)
        + (a.second - b.second) * (a.second - b.second);
}

void solve(int t)
{
    int n; cin >> n;
    vector<pair<int, int>> vs(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        vs[i] = {x, y};
    }

    if (n % 2 == 1) {
        cout << "no\n";
        return;
    }

    for (int i = 0; i < n / 2; i++) {
        auto a = vs[i], b = vs[i + 1];
        auto c = vs[n/2 + i], d = vs[(n/2 + i + 1) % n];
        int dist1 = dist(a, b);
        int dist2 = dist(c, d);
        if (dist1 != dist2 || 
                (a.first - b.first) * (c.second - d.second) != (c.first - d.first) * (a.second - b.second)) {
            cout << "no\n";
            return;
        }
    }
    cout << "yes\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

