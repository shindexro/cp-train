#include <bits/stdc++.h>
using namespace std;
#define N (int)1e5
template <class T>
T& unmove(T&& t)
{
    return t;
}

vector<int> primes = { 2 };
int ans = -1;

bool is_prime(long long num)
{
    for (auto p : primes) {
        if (1ll * p * p > num) {
            return true;
        } else if (num % p == 0) {
            return false;
        }
    }
    return true;
}

void find_combinations(vector<int>& combination, int sz, int idx, int sum)
{
    if (combination.size() == sz) {
        for (auto n : combination) {
            cout << n << " ";
        }
        cout << "sum=" << sum << "\n";
        if (ans == -1) {
            ans = sum;
        }
        ans = min(ans, sum);
        return;
    }
    if (idx >= primes.size() || (ans != -1 && sum + primes[idx] > ans)) {
        return;
    }

    bool ok = true;
    for (auto n : combination) {
        string s1 = to_string(n);
        string s2 = to_string(primes[idx]);
        if (!(is_prime(stoll(s1 + s2)) && is_prime(stoll(s2 + s1)))) {
            ok = false;
            break;
        }
    }

    if (ok) {
        combination.push_back(primes[idx]);
        find_combinations(combination, sz, idx + 1, sum + primes[idx]);
        combination.pop_back();
    }
    find_combinations(combination, sz, idx + 1, sum);
}

int main()
{
    for (int i = 3; i <= N; i++) {
        bool ok = true;
        for (auto p : primes) {
            if (1ll * p * p > i) {
                break;
            }
            if (i % p == 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            primes.push_back(i);
        }
    }

    find_combinations(unmove(vector<int>()), 5, 0, 0);
    cout << ans << "\n";

    return 0;
}
