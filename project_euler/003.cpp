#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n = 600851475143ll;
    ll factor = 2;

    while (n > 1) {
        if (n % factor == 0) {
            n /= factor;
        } else {
            factor++;
        }
    }

    cout << factor << "\n";

    return 0;
}
