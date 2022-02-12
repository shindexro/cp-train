#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void add_to_family(map<string, set<int>>& family, string s, string cur, int digit)
{
    if (cur.size() == s.size()) {
        family[cur].insert(stoi(s));
        return;
    }

    add_to_family(family, s, cur + s[cur.size()], digit);
    if (digit == -1 || s[cur.size()] - '0' == digit) {
        add_to_family(family, s, cur + '*', s[cur.size()] - '0');
    }
}

int main()
{
    vector<int> primes;
    map<string, set<int>> family;
    primes.push_back(2);
    for (int n = 3; n < 1000000; n += 2) {
        bool is_prime = true;
        for (auto p : primes) {
            if (n % p == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {

            primes.push_back(n);
            string s = to_string(n);
            add_to_family(family, s, "", -1);
        }
    }

    int ans = -1;
    for (auto& [f, ps] : family) {
        if (ps.size() == 8) {
            if (ans == -1) {
                ans = *ps.begin();
            }
            ans = min(*ps.begin(), ans);
        }
    }
    cout << ans << "\n";

    return 0;
}
