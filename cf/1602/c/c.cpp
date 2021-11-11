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

    vector<int> freq(31);
    for (int i = 0; i < n; i++) {
        int cur = v[i];
        for (int j = 0; j < 30; j++) {
            if (cur & 1) {
                freq[j]++;
            }
            cur >>= 1;
        }
    }

    int fact = 0;
    for (int f : freq) {
        fact = gcd(fact, f);
    }

    for (int i = 1; i <= n; i++) {
        if (fact % i == 0) {
            cout << i << " ";
        }
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
