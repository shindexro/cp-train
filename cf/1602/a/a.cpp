#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve(int tc)
{
    string s;
    cin >> s;

    int idx = min_element(s.begin(), s.end()) - s.begin();

    cout << s[idx] << " " << s.substr(0, idx) << s.substr(idx + 1, s.size()) << "\n";
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
