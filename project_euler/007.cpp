#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    vector<ll> primes;
    primes.push_back(2);
    ll n = 3;

    while (primes.size() < 10001) {
        bool is_prime = true;
        for (ll p : primes) {
            if (n % p == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            primes.push_back(n);
        }
        n += 2;
    }

    cout << primes.back() << "\n";

    return 0;
}
