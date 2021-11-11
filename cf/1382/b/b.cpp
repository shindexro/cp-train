#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve(int tc)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    bool win = true;
    for (int i = n - 2; i >= 0; i--) {
        if (win) {
            if (v[i] >= 2) {
                win = true;
            } else {
                win = false;
            }
        } else {
            win = true;
        }
    }

    if (win) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve(t);
    }
}
