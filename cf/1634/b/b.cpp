#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve(int tc)
{
    int n;
    ll x, y;
    cin >> n >> x >> y;

    vector<ll> v(n);
    for (auto& a : v) {
        cin >> a;
    }

    x = x & 0b11;
    y = y & 0b11;

    set<int> possible;
    possible.insert(x);
    for (auto a : v) {
        set<int> new_possible;
        for (auto d : possible) {
            new_possible.insert((d + a) & 0b11);
            new_possible.insert((d ^ a) & 0b11);
        }
        possible = new_possible;
    }

    if (possible.find(y) != possible.end()) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
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
