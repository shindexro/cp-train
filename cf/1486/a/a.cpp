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
    for (int& i : v)
        cin >> i;

    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += v[i];

        if (cnt < i) {
            cout << "NO\n";
            return;
        }

        cnt -= i;
    }
    cout << "YES\n";
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
