#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve(int tc)
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int left = 0; left < i; left++)
            cout << '(';
        for (int left = 0; left < i; left++)
            cout << ')';
        for (int left = 0; left < n - i; left++)
            cout << '(';
        for (int left = 0; left < n - i; left++)
            cout << ')';
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
        solve(t);
}
