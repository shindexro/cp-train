#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve(int tc)
{
    int n;
    cin >> n;
    vector<int> v(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int l = 0, r = n - 1;
    while (l < r) {
        w[l] = v[r];
        w[r] = -v[l];
        l++;
        r--;
    }

    if (l == r) {
        w[l] = -v[l - 1];
        w[l - 1] += v[l];

        if (w[l - 1] == 0) {
            w[l] -= v[l - 1];
            w[l - 1] += v[l];
        }
    }

    for (int a : w) {
        cout << a << " ";
    }
    cout << "\n";
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
