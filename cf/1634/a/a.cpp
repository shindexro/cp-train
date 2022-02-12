#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve(int tc)
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string rs = s;
    reverse(rs.begin(), rs.end());

    if (k == 0 || s.compare(rs) == 0) {
        cout << 1 << "\n";
    } else {
        cout << 2 << "\n";
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
