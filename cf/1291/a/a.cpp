#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve(int tc)
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += s[i] - '0';
    }

    for (int i = n - 1; i >= 0; i--) {
        int d = s[i] - '0';
        if (sum % 2 == 0 && d & 1) {
            cout << s.substr(0, i + 1) << "\n";
            return;
        }

        sum -= d;
    }
    cout << "-1\n";
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
