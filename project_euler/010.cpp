#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    vector<int> primes;
    primes.push_back(2);
    int n = 3;

    while (n < 2000000) {
        bool is_prime = true;
        for (auto p : primes) {
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

    cout << accumulate(primes.begin(), primes.end(), 0ll) << "\n";

    return 0;
}
