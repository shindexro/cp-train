#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> primes;

void buildPrimes(int bound)
{
    primes.push_back(2);
    for (int n = 3; n <= bound; n += 2) {
        bool isPrime = true;
        for (int p : primes) {
            if (p * p > n * n) break;
            if (n % p == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) primes.push_back(n);
    }
}

void solve(int t)
{
    int d; cin >> d;
    int p = *lower_bound(primes.begin(), primes.end(), 1 + d);
    int q = *lower_bound(primes.begin(), primes.end(), p + d);
    cout << p * q << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
    buildPrimes(1e6);
	for (int t = 1; t <= T; t++) solve(t);
}

