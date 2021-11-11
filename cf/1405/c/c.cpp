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

    for (int i = 0; i < k; i++) {
        int idx = i;
        map<char, int> freq;
        while (idx < n) {
            freq[s[idx]]++;
            idx += k;
        }

        if (freq['0'] && freq['1']) {
            cout << "NO\n";
            return;
        }

        if (freq['0']) {
            s[i] = '0';
        } else if (freq['1']) {
            s[i] = '1';
        }
    }

    int a = count(s.begin(), s.begin() + k, '0');
    int b = count(s.begin(), s.begin() + k, '1');
    int q = count(s.begin(), s.begin() + k, '?');

    if (a <= b + q && b <= a + q) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
