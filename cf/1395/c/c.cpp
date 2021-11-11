#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve(int tc)
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n), w(m);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> w[i];
    }

    for (int a = 0; a < 512; a++) {
        bool a_ok = true;
        for (int i = 0; i < n; i++) {
            int i_ok = false;
            for (int j = 0; j < m; j++) {
                if ((v[i] & w[j] & a) == (v[i] & w[j])) {
                    i_ok = true;
                }
            }
            if (!i_ok) {
                a_ok = false;
            }
        }
        if (a_ok) {
            cout << a << "\n";
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve(t);
    }
}
